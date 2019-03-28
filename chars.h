#ifndef CHARS
#define CHARS
#include<iostream>
using namespace std;

class chars /* To save the char and count how many*/
{
	protected:
		
		char c;
		int count;
		
	public:
		
		chars(char=' ',int=0);
	
		void setChar(char);
		void setCount(int);
		
		char getChar();
		int getCount();
		
		
		
};
#endif
