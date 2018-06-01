#include"node.h"
#include"compiler.hpp"
#include<iostream>
#include "RGenerator.cpp"
extern FILE *yyin;
using namespace std;
extern node* root;
int yyparse();
int main()
{
	yyin = fopen("test.c","r");
	yyparse();
	//root->debugInfo(true,true); //show info all the instructions following,no extand
	cout<<endl<<endl;
	//root->next->next->debugInfo(false,true);//only show this instruction,extand
	cout << endl << "中间树" << endl;
	RGenerator translator(root);
	return 0;
}
