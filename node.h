#ifndef _NODE_H
#define _NODE_H
#include<string>
#include<vector>
#include"element.h"
#include<stdarg.h>
using namespace std;
class node{
public:
	string type;
	node* next;
	vector<element*> contents;
	vector<node*> sub;
	node(string type,node* next,int eleNum,...){
		this->type = type;
		this->next = next;
		va_list ap;
		va_start(ap, eleNum);
		for(int i=0;i<eleNum;i++)
			contents.push_back(va_arg(ap, element*));
	}
	void addSub(int subNum,...){
		va_list ap;
		va_start(ap, subNum);
		for(int i=0;i<subNum;i++)
			sub.push_back(va_arg(ap, node*));
	}
	void addContents(int nodeNum,...){
		va_list ap;
		va_start(ap, nodeNum);
		for(int i=0;i<nodeNum;i++)
			{
				node* t = va_arg(ap, node*);
				this->contents.insert(this->contents.end(),t->contents.begin(),t->contents.end());
				delete t;
			}
	}
};
#endif
