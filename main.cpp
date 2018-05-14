#include"node.h"
#include"compiler.hpp"
#include<iostream>
extern FILE *yyin;
using namespace std;
extern node* root;
int main()
{
	yyin = fopen("test.c","r");
	yyparse();
	/*node* t=root;
	//first output contents, then sub(first contents, then sub, then next), then next.
	while(t!=NULL){
		cout<<t->type<<endl;
		for(int i=0;i<t->contents.size();i++)
			cout<<t->contents[i]->lineNum<<"  "<<t->contents[i]->name<<"  "<<t->contents[i]->content<<endl;
		for(int i=0;i<t->sub.size();i++){
				node* tt = t->sub[i];
				while(tt!=NULL){
						cout<<tt->type<<endl;
						for(int i=0;i<tt->contents.size();i++)
							cout<<tt->contents[i]->lineNum<<"  "<<tt->contents[i]->name<<"  "<<tt->contents[i]->content<<endl;
							tt=tt->next;
					}
			}
		t=t->next;
	}*/
	root->debugInfo(true);
	cout<<endl<<endl;
	root->next->next->debugInfo(false);
	cout<<endl<<endl;
	root->next->next->next->debugInfo(false);
	return 0;
}
