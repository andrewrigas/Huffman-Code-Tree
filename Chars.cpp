#include<iostream>
#include"chars.h"
using namespace std;

chars::chars(char x,int s)
{
	setChar(x);
	setCount(s);
}

void chars::setChar(char x)
{
	c=x;
}

void chars::setCount(int x)
{
	count=x;
} 

char chars::getChar()
{
	return c;
} 

int chars::getCount()
{
	return count;
}
