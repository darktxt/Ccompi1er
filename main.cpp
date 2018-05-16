#include"node.h"
#include"compiler.hpp"
#include<iostream>
extern FILE *yyin;
using namespace std;
extern node* root;
int yyparse();
int main()
{
	yyin = fopen("test.c","r");
	yyparse();
	root->debugInfo(true,false); //show info all the instructions following,no extand
	cout<<endl<<endl;
	root->next->next->debugInfo(false,true);//only show this instruction,extand
	return 0;
}
