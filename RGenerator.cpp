#include <iostream>
#include "node.h"
#include <string>

char* itoa(int i){
	static char str[20];
	sprintf(str,"%d",i);
	return str;
}

using namespace std;
typedef struct {
	bool state;	
	string name;
	string type;
} VAR;
class Data{
private:
	
	bool *temps;//false no use
	int num;
	VAR *vars;
	VAR *ARG;
public:
	void operator=(const Data& d){
		num=d.num;
		temps = new bool [num];	
		vars = new VAR [num];	
		ARG = new VAR [num];	
		for(int i=0;i<num;i++)
		{
			temps[i]=d.temps[i];
			vars[i]=d.vars[i];
		}
	}
	Data(const Data& d){
		num=d.num;
		temps = new bool [num];	
		vars = new VAR [num];	
		for(int i=0;i<num;i++)
		{
			temps[i]=d.temps[i];
			vars[i]=d.vars[i];
		}
	}
	Data(int num = 32){
		this->num=num;
		temps = new bool [num];	
		vars = new VAR [num];	
		for(int i=0;i<num;i++)
		{
			temps[i]=false;
			vars[i].state=false;
		}
	}
	~Data(){
		delete [] temps;
		delete [] vars;
	}
	int getTemp(){
		for(int i=0;i<num;i++)
		{
			if(temps[i]==false)
			{
				temps[i]=true;
				//cout<<"debug----"<<i<<endl;
				return i;
			}
		}
		return -1;
	}
	void releaseTemp(int i){
			temps[i]=false;
	}
	int setVar(string name,string type){
		for(int i=0;i<num;i++)
		{
			if(vars[i].state==false)
			{
				vars[i].state=true;
				vars[i].name=name;
				vars[i].type=type;
				return i;
			}
		}
		return -1;
	}
	int getVar(string name){
		for(int i=num-1;i>=0;i--)//find the recent one
		{
			if(vars[i].state==true)
			{
				if(vars[i].name==name)
					return i;
			}
		}
		return -1;
	}
	void releaseVar(int i){
			vars[i].state=false;
	}

	int getARG(){
		for(int i=0;i<num;i++)//find the recent one
		{
			if(vars[i].state==false)
			{
				vars[i].state = true;
				return i;
			}
		}
		return -1;
	}
	void releaseARG(){
		for(int i=0;i<num;i++){
			ARG[i].state=false;
		}
	}
};


class RGenerator{
    node* root;
	bool *labels;
	const int MAX_LABELS = 1000;
	Data r = Data(32);
public:
    RGenerator(node* root){
        this->root = root;
		labels = new bool[MAX_LABELS];
		for(int i=0;i<MAX_LABELS;i++)
		{
			labels[i]=false;
		}
        stratTranslate(this->root,r);
    }

	~RGenerator(){
		delete[] labels;
	}

	int getLabel(){
		for(int i=0;i<MAX_LABELS;i++)
		{
			if(labels[i]==false)
			{
				labels[i]=true;
				return i;
			}
		}
		return -1;
	}
	void releaseLabel(int i){
			labels[i]=false;
	}
	string stratTranslate(node* root,Data* r) {
		node* t = root;
		string value="";
		while (t) {
            if(t->type.compare("function_definition")==0){
                cout << "FUNCTION" << t->contents[1]->content << "" << endl;
                loop(t,r);

            }

            else if(t->type.compare("parameter_declaration")==0){
                cout << "PARAM " <<  t->contents[1]->content << endl;
                loop(t,r);
            }
            else if (t->type.compare("declaration")==0){
				string ttype = t->sub[0]->contents[0]->content;
                for(int i=0;i<t->sub[1]->sub.size();i++){
					node* tt = t->sub[1]->sub[i];
					//cout<<"debug----"<<tt->contents[0]->content<<endl;
					r->setVar(tt->contents[0]->content,ttype);
					loop(tt,r);
				}
            }
			else if (t->type.find("expression")!=-1&&t->type.compare("conditional_expression2")!=0){
				node* tt=t->sub[0];
				string r1,r2,r3,l;
                if(tt->sub.size()==0){
					if(tt->contents[0]->name.compare("IDENTIFIER")==0)
						r1 = string("var").append(itoa(r->getVar(tt->contents[0]->content)));
					else if(tt->contents[0]->name.compare("CONSTANT")==0){
						int i = r->getTemp();
						cout<<"Temp"<<itoa(i)<<" = "<<"#"<<tt->contents[0]->content<<endl;
						r1 = string("Temp").append(itoa(i));
					}						
                }
				else
                	r1 = stratTranslate(tt,r);  
				
		
				tt=t->sub[2];
				if(tt->sub.size()==0){
					if(tt->contents[0]->name.compare("IDENTIFIER")==0)
						r3 = string("var").append(itoa(r->getVar(tt->contents[0]->content)));
					else if(tt->contents[0]->name.compare("CONSTANT")==0){
						int i = r->getTemp();
						cout<<"Temp"<<itoa(i)<<" = "<<"#"<<tt->contents[0]->content<<endl;
						r3 = string("Temp").append(itoa(i));
					}						
                }
				else
                	r3 = stratTranslate(tt,r);

				tt = t->sub[1];
				r2 = tt->contents[0]->content;
				if(tt->contents[0]->name.compare("assignment_operator")==0){
					cout<<r1<<" "<<r2<<" "<<r3<<endl;
					value = r1;
				}
				else{
					l = string("Temp").append(itoa(r->getTemp()));
					value = l;
					cout<< l<<" = "<<r1<<" "<<r2<<" "<<r3<<endl;
				}
				         
            }

			else if(t->type == "if_statement"){
				string resReg = stratTranslate(t->sub[0],r);
				int label_true = getLabel();
				int label_false = getLabel();
				cout << "IF " << resReg << " == 0 GOTO label_" << label_true << endl;
				cout << "GOTO label_" << label_false << endl;
				cout << "LABEL label_" << label_true<<":" << endl;
				stratTranslate(t->sub[1],r);
				cout << "LABEL label_" << label_false <<":" << endl;
			}


			else if(t->type == "if_else_statement"){
				int label_true = getLabel();
				int label_false = getLabel();
				int label_next = getLabel();
				string resReg = stratTranslate(t->sub[0],r);
				cout << "IF " << resReg << " == 0 GOTO label_" << label_true << endl;
				cout << "GOTO label_" << label_false << endl;
				cout << "LABEL label_" << label_true<<":" << endl;
				stratTranslate(t->sub[1],r);
				cout << "GOTO label_" << label_next << endl;
				cout << "LABEL label_" << label_false <<":" << endl;
				stratTranslate(t->sub[2],r);
				cout << "LABEL label_" << label_next <<":" << endl;
			}


			else if(t->type == "while_statement"){
				int label_while = getLabel();
				int label_start = getLabel();
				int label_end = getLabel();
				cout << "LABEL label_" << label_while <<":" << endl;
				string resReg = stratTranslate(t->sub[0],r);
				cout << "IF " << resReg << " == 0 GOTO label_" << label_start << endl;
				cout << "GOTO label_" << label_end << endl;
				cout << "LABEL label_" << label_start <<":" << endl;
				stratTranslate(t->sub[1],r);
				cout << "GOTO label_" << label_while << endl;
				cout << "LABEL label_" << label_end <<":" << endl;
			}

			else if(t->type == "do_while_statement"){
				int label_while = getLabel();
				cout << "LABEL label_" << label_while <<":" << endl;
				stratTranslate(t->sub[0],r);
				string resReg = stratTranslate(t->sub[1],r);
				cout << "IF " << resReg << " == 0 GOTO label_" << label_while << endl;
			}

			else if(t->type == "for_statement_exp3"){
				int label_for = getLabel();
				int label_start = getLabel();
				int label_end = getLabel();
				stratTranslate(t->sub[0],r);
				cout << "LABEL label_" << label_for <<":" << endl;
				string resReg = stratTranslate(t->sub[1],r);
				cout << "IF " << resReg << " == 0 GOTO label_" << label_start << endl;
				cout << "GOTO label_" << label_end << endl;
				cout << "LABEL label_" << label_start <<":" << endl;
				stratTranslate(t->sub[3],r);
				stratTranslate(t->sub[2],r);
				cout << "GOTO label_" << label_for << endl;
				cout << "LABEL label_" << label_end <<":" << endl;
			}

			t = t->next; 
		}
		return value;
			
	}        
	  

    string stratTranslate(node* root,Data r) {
		node* t = root;
		string value="";
		while (t) {
            if(t->type.compare("function_definition")==0){
                cout << "FUNCTION " << t->contents[1]->content << " :" << endl;
				if(t->contents[1]->content.find("main")!= -1){
                	//cout << t->sub[0]->type<<endl;
					//cout << t->sub[0]->contents[0]->content<<endl;
					//cout << t->sub.size()<<endl;
					loop(t,r);
				}
				else{
					loop(t,r);
				}
            }

            else if(t->type.compare("parameter_declaration")==0){
                cout << "PARAM " <<  t->contents[1]->content << endl;
                loop(t,r);
            }
            else if (t->type.compare("declaration")==0){
				string ttype = t->sub[0]->contents[0]->content;
                for(int i=0;i<t->sub[1]->sub.size();i++){
					node* tt = t->sub[1]->sub[i];
					//cout<<"debug----"<<tt->contents[0]->content<<endl;
					r.setVar(tt->contents[0]->content,ttype);
					loop(tt,r);
				}
            }
			else if (t->type.find("expression")!=-1&&t->type.compare("conditional_expression2")!=0){
				node* tt=t->sub[0];
				string r1,r2,r3,l;
                if(tt->sub.size()==0){
					if(tt->contents[0]->name.compare("IDENTIFIER")==0)
						r1 = string("var").append(itoa(r.getVar(tt->contents[0]->content)));
					else if(tt->contents[0]->name.compare("CONSTANT")==0){
						int i = r.getTemp();
						cout<<"Temp"<<itoa(i)<<" = "<<"#"<<tt->contents[0]->content<<endl;
						r1 = string("Temp").append(itoa(i));
					}						
                }
				else
                	r1 = stratTranslate(tt,new Data(r));  
				
		
				tt=t->sub[2];
				if(tt->sub.size()==0){
					if(tt->contents[0]->name.compare("IDENTIFIER")==0)
						r3 = string("var").append(itoa(r.getVar(tt->contents[0]->content)));
					else if(tt->contents[0]->name.compare("CONSTANT")==0){
						int i = r.getTemp();
						cout<<"Temp"<<itoa(i)<<" = "<<"#"<<tt->contents[0]->content<<endl;
						r3 = string("Temp").append(itoa(i));
					}						
                }
				else
                	r3 = stratTranslate(tt,new Data(r));

				tt = t->sub[1];
				r2 = tt->contents[0]->content;
				if(tt->contents[0]->name.compare("assignment_operator")==0){
					cout<<r1<<" "<<r2<<" "<<r3<<endl;
					value = r1;
				}
				else{
					l = string("Temp").append(itoa(r.getTemp()));
					value = l;
					cout<< l<<" = "<<r1<<" "<<r2<<" "<<r3<<endl;
				}
				         
            }

			else if(t->type == "if_statement"){
				string resReg = stratTranslate(t->sub[0],r);
				int label_true = getLabel();
				int label_false = getLabel();
				cout << "IF " << resReg << " == 0 GOTO label_" << label_true << endl;
				cout << "GOTO label_" << label_false << endl;
				cout << "LABEL label_" << label_true<<":" << endl;
				stratTranslate(t->sub[1],r);
				cout << "LABEL label_" << label_false <<":" << endl;
			}


			else if(t->type == "if_else_statement"){
				int label_true = getLabel();
				int label_false = getLabel();
				int label_next = getLabel();
				string resReg = stratTranslate(t->sub[0],r);
				cout << "IF " << resReg << " == 0 GOTO label_" << label_true << endl;
				cout << "GOTO label_" << label_false << endl;
				cout << "LABEL label_" << label_true<<":" << endl;
				stratTranslate(t->sub[1],r);
				cout << "GOTO label_" << label_next << endl;
				cout << "LABEL label_" << label_false <<":" << endl;
				stratTranslate(t->sub[2],r);
				cout << "LABEL label_" << label_next <<":" << endl;
			}


			else if(t->type == "while_statement"){
				int label_while = getLabel();
				int label_start = getLabel();
				int label_end = getLabel();
				cout << "LABEL label_" << label_while <<":" << endl;
				string resReg = stratTranslate(t->sub[0],r);
				cout << "IF " << resReg << " == 0 GOTO label_" << label_start << endl;
				cout << "GOTO label_" << label_end << endl;
				cout << "LABEL label_" << label_start <<":" << endl;
				stratTranslate(t->sub[1],r);
				cout << "GOTO label_" << label_while << endl;
				cout << "LABEL label_" << label_end <<":" << endl;
			}

			else if(t->type == "do_while_statement"){
				int label_while = getLabel();
				cout << "LABEL label_" << label_while <<":" << endl;
				stratTranslate(t->sub[0],r);
				string resReg = stratTranslate(t->sub[1],r);
				cout << "IF " << resReg << " == 0 GOTO label_" << label_while << endl;
			}

			else if(t->type == "for_statement_exp3"){
				int label_for = getLabel();
				int label_start = getLabel();
				int label_end = getLabel();
				stratTranslate(t->sub[0],r);
				cout << "LABEL label_" << label_for <<":" << endl;
				string resReg = stratTranslate(t->sub[1],r);
				cout << "IF " << resReg << " == 0 GOTO label_" << label_start << endl;
				cout << "GOTO label_" << label_end << endl;
				cout << "LABEL label_" << label_start <<":" << endl;
				stratTranslate(t->sub[3],r);
				stratTranslate(t->sub[2],r);
				cout << "GOTO label_" << label_for << endl;
				cout << "LABEL label_" << label_end <<":" << endl;
			}

			else if(t->type == "function_call"){
				// have parameter
				if(t->sub.size()==2){
					node* s = t->sub[1];
					while(s!=nullptr){
						int i = r.getARG();
						if(s->type == "primary_expression"){
							if(s->contents[0]->name == "CONSTANT"){
								cout << "ARG" << i << " :=  " <<s->contents[0]->content  << endl;
							}
							if(s->contents[0]->name == "IDENTIFIER"){
								string varname = s->contents[0]->content;
								cout << "ARG" << i << " :=  Var" << r.getVar(s->contents[0]->content)  << endl;
							}
						}
						else{
							string res = stratTranslate(s,r);
							cout << "ARG" << i << " :=  "  << res << endl;
						}
						
						s = s->next;
					}
					
				}
				cout << "CALL " << t->sub[0]->contents[0]->content << endl;
				r.releaseARG();
			}

			else if(t->type == "return_statement"){
				if(t->sub.size()==0){
					cout << "RETURN" << endl;
				}
				else{
					node* s = t->sub[0];
					string res;
					if(s->type == "primary_expression"){
						if(s->contents[0]->name == "CONSTANT"){
							res = s->contents[0]->content;
						}
						if(s->contents[0]->name == "IDENTIFIER"){
							res = s->contents[0]->content;
						}
					}
					else{
						res = stratTranslate(s,r);
					}
					cout << "RETURN " << res << endl;
				}
			}

			t = t->next; 
		}
		return value;
			
	}        
	
	void loop(node* t,Data* r){
        for (int i = 0; i < t->sub.size(); i++){
                stratTranslate(t->sub[i],r);
        }
    }            

    void loop(node* t,Data r){
        for (int i = 0; i < t->sub.size(); i++){
                stratTranslate(t->sub[i],r);
        }
    }


};

