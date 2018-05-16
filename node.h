#ifndef _NODE_H
#define _NODE_H
#include<string>
#include<vector>
#include"element.h"
#include<stdarg.h>
#include<iostream>
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
	void debugInfo(bool next=true,bool expand=true) {
		node* t = this;
		while (t) {
			cout << t->type << endl;
			for (int i = 0; i < t->contents.size(); i++)
				cout << t->contents[i]->lineNum << "  " << t->contents[i]->name << "  " << t->contents[i]->content << endl;
			if(expand)
				for (int i = 0; i < t->sub.size(); i++)
					t->sub[i]->debugInfo();
			if(next)
				t = t->next;
			else
				break;
		}
	}
};
#endif
