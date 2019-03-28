#include<iostream>
#include"chars.h"
#include"linkedlist.h"
using namespace std;

void linkedlist::addElement(chars b)
{
	linkedlist *temp=new linkedlist;
	temp->data=b;
	temp->next=NULL;
	if(top==NULL)
	{
		top=temp;
		size++;
	}
	else
	{
		temp->next=top;
		top=temp;
		size++;
	}
}

void linkedlist::setSize(int s)
{
	size=s;
}

void linkedlist::setElement(chars b,int x)
{
	linkedlist *curr=top;
	for(int i=0;i<x;i++)
	{
		curr=curr->next;
	}
	curr->data=b;
}

void linkedlist::popElement(int x)
{
	linkedlist *curr=top;
	if(x==0)
	{
		top=top->next;
		delete curr;
		size--;
	}
	else
	{
		for(int i=0;i<x-1;i++)
		{
			curr=curr->next;
		}
		linkedlist *temp=new linkedlist;
		temp=curr->next;
		curr->next=temp->next;
		delete temp;
		size--;	
	}
	
}
chars linkedlist::getElement(int x)
{
	linkedlist *curr=top;
	for(int i=0;i<x;i++)
	{
		curr=curr->next;
	}
	return curr->data;
}
 
int linkedlist::getSize()
{
	return size;
}

bool linkedlist::isTree() 
{
	if(data.getChar()=='*')
	{
		return true;
	}
	else
	{
		return false;
	}
}


