#include<iostream>
#include<vector>
#include<string>
#include"linkedlist.h"
#include"chars.h"
#include"stack.h"
#include<fstream>
#include<sstream>
using namespace std;


struct node
{
 	node *left;
 	node *right;
 	int count;
	char character;
 	string code;
};

vector<node> nodeArray; //Public Vector node 
stack path;

node  extractMin()
{ 
	int temp = (int) INT_MAX;
    vector<node>::iterator i1,pos;
    for(i1 = nodeArray.begin();i1!=nodeArray.end();i1++)
 	{
  
  		if(temp>(*i1).count)
  		{
    		pos = i1;
     		temp = (*i1).count;
  		}
 	}
 	node temp1 = (*pos);
 	nodeArray.erase(pos);
 	return temp1;
}
                     


node getTree()
{ 
 	while(!nodeArray.empty())
 	{
   		node *temp = new node;   
      	node *temp1 = new node;
   		node *temp2 = new node;
      	*temp1 = extractMin();
   		*temp2 = extractMin();
   		temp->left= temp1;
   		temp->right = temp2;
   		temp->count = temp1->count+temp2->count;
   		nodeArray.push_back(*temp);
   		
   		if(nodeArray.size() == 1)//only the root node exsits
   		{
    		break;
   		}
 	}
    return nodeArray[0];
}


void generatecodes(node * temproot,string s)
{
   	node * root1 = new node;
   	root1 = temproot;
  
   	root1->code = s;
   	if(root1 == NULL)
   	{
   	}
   	else if(root1->left == NULL && root1->right == NULL)
   	{
    	path.push(root1->code);
   	}
   	else
   	{
   
      	root1->left->code = s.append("0");
   		s.erase(s.end()-1);
   		root1->right->code = s.append("1");
   		s.erase(s.end()-1);
      	generatecodes(root1->left,s.append("0"));
   		s.erase(s.end()-1);
      	generatecodes(root1->right,s.append("1"));
   		s.erase(s.end()-1);
 	}
   
}
void sortinglist(linkedlist list1)
{
	chars element;
		for(int i=1;i<=list1.getSize();i++)
		for(int y=0;y<list1.getSize()-i;y++)
		{
			if(list1.getElement(y).getCount()>list1.getElement(y+1).getCount())
			{
				element=list1.getElement(y);
				list1.setElement(list1.getElement(y+1),y);
				list1.setElement(element,y+1);
			}	
		} 
	
}

void printlist(linkedlist list1)
{
	cout<<"--Char--Frequency--Code"<<endl;
		for(int i=0;i<list1.getSize();i++)
	{
		cout<<"   "<<list1.getElement(i).getChar()<<"       "<<list1.getElement(i).getCount()<<"        "<<path.getCode(i) <<endl; 	
	}	
}

int searchlist(char c,linkedlist list1)
{
	int b;
	for(int i=0;i<list1.getSize();i++)
	{
		if(c==list1.getElement(i).getChar())
		{
			b=i;
		}
	}
	return b;
}

bool exist(string c,int x)
{
	for(int i=0;i<x;i++)
	{
		if(c.compare(path.getCode(i))==0)
		{
			return true;
		}
	}
	return false;
}

int findpos(string c,int x)
{
	int b;
	for(int i=0;i<x;i++)
	{
		if(c.compare(path.getCode(i))==0)
		{
			b=i;
		}
	}
	return b;
}

int main()
{
  	node tree;
  	string line;
	string text;
	chars element;
	ifstream file;
	linkedlist list;
	
	list.setSize(0); 

	file.open("input.txt");
	
	if(file.is_open())
	{
		while(file.good())
		{
			
			getline(file,line);
			text=text+line+" ";
			
		}
	}
	else
	{
		cout<<"File didnt open.";
	}
	
	element.setChar(text[0]);
	element.setCount(1);
	list.addElement(element);
	int b=0;
	int x=1;
	do
	{
		for(int i=0;i<list.getSize();i++)
		{
			if(list.getElement(i).getChar()==text[x])
			{
				element.setChar(text[x]);
				element.setCount(list.getElement(i).getCount()+1);
				list.setElement(element,i);
				b=1;
			}
		}
		if(b==0)
		{
			element.setChar(text[x]);
			element.setCount(1);
			list.addElement(element);
		}
		x=x+1;
		b=0;
	}while(text[x]!='\0');

	sortinglist(list);


	for(int i=0;i<list.getSize();i++)
	{
		tree.count = list.getElement(i).getCount() ;
  		tree.character = list.getElement(i).getChar() ;
  		tree.left = NULL;
  		tree.right = NULL;
  		nodeArray.push_back(tree);	
	}
	
	
 	node root = getTree();
 	generatecodes(&root,"");
 	printlist(list);
 	
 	ofstream myfile;
 	myfile.open("output.txt");
 	vector<bool> bits1;//Boolean vector to conver the output to bits.
 	string bits="";
 	x=0;
 	int p;
 	//Write the results in the output.txt encoding.
 	do
 	{
	 	p=searchlist(text[x],list);
	 	bits=bits+path.getCode(p);
	 	x++;
	}while(text[x]!='\0');
	
	for(int i=0;i<bits.length();i++)
	{
		if(bits[i]=='0')
		{
			bits1.push_back(0); 
		}
		else
		{
			bits1.push_back(1); 
		}
	}
	
	//write to the output.file in bits.
	for(int i=0;i<bits1.size();i++)
	myfile<<bits1[i];
	
	cout<<"\n"<<"\nIn the output.txt is the encode.\n"<<endl<<bits<<endl<<endl;
	//decode it will be print  .
	myfile.close();
	
	
	x=0;
	string str="";
	string decode="";
	int i=0;
	do
	{
		decode=decode+bits[x];
		if(exist(decode,list.getSize()))
		{	
			p=findpos(decode,list.getSize());
			str=str+list.getElement(p).getChar(); 
			decode="";
		}
		x=x+1;
	}while(bits[x]!='\0');
	
	myfile.open("decode.txt");
	cout<<"Decode from 0s and 1s and is also saved in decoded.txt :\n\n"<<str;
	myfile<<str;
	
	
 	return 0;
}
