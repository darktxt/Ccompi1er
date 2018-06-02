#include <iostream>
#include "node.h"
#include "CodeGen.cpp"
#include <string>
#include <vector>

using namespace std;

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

};

class RGenerator{
    node* root;
	bool *labels;
	const int MAX_LABELS = 1000;
	Data r = Data(32);
	// generate llvm IR
	CodeGen cg = CodeGen("test");

	bool isloop;
	int startlabel;
	int endlabel;
	bool func_call_visual = true;
public:
    RGenerator(node* root){
        this->root = root;
		labels = new bool[MAX_LABELS];
		for(int i=0;i<MAX_LABELS;i++)
		{
			labels[i]=false;
		}
        stratTranslate(this->root,r);
		printf("end\n");
		module->print(errs(), nullptr);
		cg.generateObjectCode();
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
		return stratTranslate(root, *r);
	}      
	  

    string stratTranslate(node* root,Data r) {
		node* t = root;
		string value="";
		while (t) {
			
            if(t->type.compare("function_definition")==0){
                cout << "FUNCTION " << t->contents[1]->content << " :" << endl;
				if(t->contents[1]->content.find("main")!= -1){
					cg.getFunction("main");
					loop(t,r);
					cg.createRet("void");
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
					if(tt->contents[0]->name.compare("IDENTIFIER")==0){
						r1 = string("var").append(itoa(r.getVar(tt->contents[0]->content)));
					}
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
					if(tt->contents[0]->name.compare("IDENTIFIER")==0) {
						r3 = string("var").append(itoa(r.getVar(tt->contents[0]->content)));
					}
					else if(tt->contents[0]->name.compare("CONSTANT")==0){
						int i = r.getTemp();
						cout<<"Temp"<<itoa(i)<<" = "<<"#"<<tt->contents[0]->content<<endl;
						r3 = string("Temp").append(itoa(i));
						// int for now
						cg.createTempVar(stoi(tt->contents[0]->content), r3);
					}						
                }
				else{
					if(tt->type == "function_call"){
						func_call_visual = false;
						stratTranslate(tt,r);
						int i = r.getTemp();
						cout << "Temp" << i << " = CALL " << tt->sub[0]->contents[0]->content << endl;
						r3 = string("Temp") + to_string(i);
						r.releaseTemp(i);
					}
					else{
						r3 = stratTranslate(tt,new Data(r));
					}
                	//
				}

				tt = t->sub[1];
				r2 = tt->contents[0]->content;
				if(tt->contents[0]->name.compare("assignment_operator")==0){
					cout<< r1<<" "<<r2<<" "<<r3<<endl;
					value = r1;
					cg.createAssignVar(r1, r3);
					cg.eraseTempVar(r3);
					// a = b
				}
				else{
					l = string("Temp").append(itoa(r.getTemp()));
					value = l;
					cout<< l<<" = "<<r1<<" "<<r2<<" "<<r3<<endl;
					cg.createBinOp(l, r1, r2, r3);
					cg.eraseTempVar(r1);
					cg.eraseTempVar(r3);
				}
				         
            }

			else if(t->type == "if_statement"){
				string resReg = stratTranslate(t->sub[0],r);
				int label_true = getLabel();
				int label_false = getLabel();
				cout << "IF " << resReg << " == 0 GOTO label_" << label_true << endl;
				cout << "GOTO label_" << label_false << endl;
				cout << "LABEL label_" << label_true<<" :" << endl;
				stratTranslate(t->sub[1],r);
				cout << "LABEL label_" << label_false <<" :" << endl;
			}


			else if(t->type == "if_else_statement"){
				int label_true = getLabel();
				int label_false = getLabel();
				int label_next = getLabel();
				string resReg = stratTranslate(t->sub[0],r);
				cout << "IF " << resReg << " != 0 GOTO label_" << label_true << endl;
				cout << "GOTO label_" << label_false << endl;
				cout << "LABEL label_" << label_true<<" :" << endl;
				stratTranslate(t->sub[1],r);
				cout << "GOTO label_" << label_next << endl;
				cout << "LABEL label_" << label_false <<" :" << endl;
				stratTranslate(t->sub[2],r);
				cout << "LABEL label_" << label_next <<" :" << endl;
			}

			else if(t->type == "break"){
				cout << "GOTO label_" << this->endlabel << endl;
			}

			else if(t->type == "continue"){
				cout << "GOTO label_" << this->startlabel << endl;
			}

			else if(t->type == "while_statement"){
				int label_while = getLabel();
				int label_start = getLabel();
				int label_end = getLabel();
				isloop = true;
				startlabel = label_while;
				endlabel = label_end;

				cout << "LABEL label_" << label_while <<" :" << endl;
				string resReg = stratTranslate(t->sub[0],r);
				cout << "IF " << resReg << " != 0 GOTO label_" << label_start << endl;
				cout << "GOTO label_" << label_end << endl;
				cout << "LABEL label_" << label_start <<" :" << endl;
				stratTranslate(t->sub[1],r);
				cout << "GOTO label_" << label_while << endl;
				cout << "LABEL label_" << label_end <<" :" << endl;
			}

			else if(t->type == "do_while_statement"){
				int beginlabel = getLabel();
				startlabel = getLabel();
				endlabel = getLabel();
				cout << "LABEL label_" << beginlabel <<" :" << endl;
				stratTranslate(t->sub[0],r);
				cout << "LABEL label_" << startlabel <<" :" << endl;
				string resReg = stratTranslate(t->sub[1],r);
				cout << "IF " << resReg << " != 0 GOTO label_" << beginlabel << endl;
				cout << "LABEL label_" << endlabel <<" :" << endl;

			}

			else if(t->type == "for_statement_exp3"){
				int label_judge = getLabel();
				int label_start = getLabel();
				
				
				startlabel = getLabel();
				endlabel = getLabel();

				stratTranslate(t->sub[0],r);
				cout << "LABEL label_" << label_judge <<" :" << endl;
				string resReg = stratTranslate(t->sub[1],r);
				cout << "IF " << resReg << " != 0 GOTO label_" << label_start << endl;
				cout << "GOTO label_" << endlabel << endl;
				cout << "LABEL label_" << label_start <<" :" << endl;
				stratTranslate(t->sub[3],r);
				cout << "LABEL label_" << startlabel <<" :" << endl;
				stratTranslate(t->sub[2],r);
				cout << "GOTO label_" << label_judge << endl;
				cout << "LABEL label_" << endlabel <<" :" << endl;
			}

			else if(t->type == "function_call"){
				// have parameter
				vector<string> ARG;
				if(t->sub.size()==2){
					node* s = t->sub[1];
					vector<int> TEMP;
					while(s!=nullptr){
						if(s->type == "primary_expression"){
							if(s->contents[0]->name == "CONSTANT"){
								int i = r.getTemp();
								cout << "Temp" << i << " = #" << s->contents[0]->content <<endl;
								//cout << "ARG" << "  " << "Temp" << i  << endl;
								string argname = "Temp";
								argname += to_string(i);
								ARG.push_back(argname);
								TEMP.push_back(i);
								cg.createTempVar(stoi(s->contents[0]->content), argname);
							}
							if(s->contents[0]->name == "IDENTIFIER"){
								string varname = s->contents[0]->content;
								//cout << "ARG" << "  Var" << r.getVar(s->contents[0]->content)  << endl;
								string argname = "var";
								argname += to_string(r.getVar(s->contents[0]->content));
								ARG.push_back(argname);
							}
						}
						else{
							string res = stratTranslate(s,r);
							ARG.push_back(res);
						}

						s = s->next;
					}
					for(int j=ARG.size()-1;j>=0;j--){
						cout << "ARG" << " "  << ARG[j] << endl;
					}
				}
				if(func_call_visual == true) {
					cout << "CALL " << t->sub[0]->contents[0]->content << endl;
					cg.callFunction(t->sub[0]->contents[0]->content, ARG);
				}
				else{
					func_call_visual = true;
				}
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
							int i = r.getTemp();
							cout << "Temp" << i << " = #" << s->contents[0]->content << endl;
							res = "Temp";
							res = res + to_string(i);
						}
						if(s->contents[0]->name == "IDENTIFIER"){
							res = "var ";
							res += r.getVar(s->contents[0]->content);
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

