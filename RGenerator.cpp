#include <iostream>
#include "node.h"
#include <string>
using namespace std;

class RGenerator{
    node* root;
public:
    RGenerator(node* root){
        this->root = root;
        stratTranslate(this->root);
    }

    void stratTranslate(node* root) {
		node* t = root;
		while (t) {
            if(t->type.compare("function_definition")==0){
                cout << "FUNCTION " << t->contents[1]->content << " :" << endl;
                loop(t);
            }

            else if(t->type.compare("parameter_declaration")==0){
                cout << "PARAM " <<  t->contents[1]->content << endl;
                loop(t);
            }
            else if (t->type.compare("declaration")==0){
                cout << "Not done-----------" << t->type << endl;
                for(int i=0;i<t->contents.size();i++){
                    cout << "sub:" << t->contents[i]->content << endl;
                }
                loop(t);
            }

			t = t->next;

		}
	}

    void loop(node* t){
        for (int i = 0; i < t->sub.size(); i++){
                stratTranslate(t->sub[i]);
        }
    }


};