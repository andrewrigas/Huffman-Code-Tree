#include<iostream>
#include<string>
#include"stack.h"

using namespace std;

void stack::push(string d)
{
	
	stack* temp = new stack;
	
	temp->data = d;
	temp->next = NULL;
	
	if(top==NULL)
	{
		top=temp;
	}
	else
	{
		temp->next=top;
		top=temp;
	}
	
}

string stack::pop()
{
	
	if(top==NULL)
	{
		string p="Empty linkedstack !\n";
		return p;
	}
	else if(top->next==NULL)
	{	
		stack *temp=top;
		top=NULL;
		return temp->data;
		delete temp;
	}
	else
	{
		stack *temp=top;
		top=top->next;
		return temp->data;
		delete temp;	
	}
	
		
}

string stack::peek(){
	
	if(top==NULL)
	{
		cout<<"Empty linkedstack !\n";
	}
	else
	{
		
		return top->data;
		
	}
	
}

bool stack::isEmpty(){
	
	if(top==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string stack::getCode(int x)
{
	stack *curr=top;
	for(int i=0;i<x;i++)
	{
		curr=curr->next;
	}
	return curr->data;	
} 




