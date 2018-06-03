#include"node.h"
#include"compiler.hpp"
#include<iostream>
#include "RGenerator.cpp"
extern FILE *yyin;
using namespace std;
extern node* root;
extern bool hasError;
extern int errorNum;
int yyparse();
int node::ID = 0;
int main()
{
	yyin = fopen("test.c","r");
	yyparse();
<<<<<<< HEAD
	
	cout<<endl<<endl;
	
=======
	root->debugInfo(true,true); //show info all the instructions following,no extand
	cout<<endl<<endl;
	root->next->next->debugInfo(false,true);//only show this instruction,extand
>>>>>>> 080b276d7c191802d11d83f8bde3b099f39c7ab5
	if(!hasError){
		streambuf* coutBuf = cout.rdbuf(); 
		ofstream of("tree.txt"); 
		cout.rdbuf(of.rdbuf());
		root->debugInfo(true,true); //show info all the instructions following,extand
		of.close();
		cout.rdbuf(coutBuf);
		cout << endl << "中间树" << endl;
		RGenerator translator(root);
	}
	else{
		cout<<"There are "<<errorNum<<" syntax error!"<<endl;	
	}
	return 0;
}
