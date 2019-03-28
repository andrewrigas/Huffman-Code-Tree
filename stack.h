#ifndef STACK	
#define STACK
#include<iostream>
#include<string>
using namespace std;

class stack {
	
	private:
		string data;
		stack* top;
		stack* next;
	public:
		
		stack()
		{
			top=NULL;
			next=NULL;
		}
	
	void push(string);
	string pop();
	string peek();
	bool isEmpty();
	string getCode(int x);
	
};
#endif
