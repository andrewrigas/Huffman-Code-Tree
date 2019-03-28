#ifndef LINKEDLIST
#define LINKEDLIST
#include<iostream>
#include"chars.h"
using namespace std;

class linkedlist : public chars
{
	protected:
		chars data;
		int size;
		linkedlist *next;
		linkedlist *top;
	public:
		
		linkedlist()
		{
			next=NULL;
			top=NULL;
		};
		
		void addElement(chars);
		void setSize(int);
		void setElement(chars,int);
		void popElement(int x);
		
		int getSize();
		chars getElement(int x);
		bool isTree();
		
};
#endif
