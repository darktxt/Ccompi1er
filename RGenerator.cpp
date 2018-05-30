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
public:
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
		for(int i=0;i<num;i++)
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
public:
    RGenerator(node* root){
        this->root = root;
        stratTranslate(this->root);
    }

    string stratTranslate(node* root,Data* r=NULL) {
		node* t = root;
		string value="";
		while (t) {
            if(t->type.compare("function_definition")==0){
                cout << "FUNCTION " << t->contents[1]->content << " :" << endl;
                loop(t,new Data());
            }

            else if(t->type.compare("parameter_declaration")==0){
                cout << "PARAM " <<  t->contents[1]->content << endl;
                loop(t,r);
            }
            else if (t->type.compare("declaration")==0){
                cout << "Not done-----------" << t->type << endl;
                /*for(int i=0;i<t->contents.size();i++){
                    cout << "sub:" << t->contents[i]->content << endl;
                }*/
				r->setVar(t->contents[1]->content,t->contents[0]->content);
                loop(t,r);
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
				
				tt = t->sub[1];
				r2 = tt->contents[0]->content;
		
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

				
				if(r2.compare("=")==0){
					cout<<r1<<" = "<<r3<<endl;
				}
				else{
					l = string("Temp").append(itoa(r->getTemp()));
					value = l;
					cout<< l<<" = "<<r1<<" "<<r2<<" "<<r3<<endl;
				}
				         
            }
			t = t->next; 
		}
		return value;
			
	}                         

    void loop(node* t,Data* r=NULL){
        for (int i = 0; i < t->sub.size(); i++){
                stratTranslate(t->sub[i],r);
        }
    }


};

