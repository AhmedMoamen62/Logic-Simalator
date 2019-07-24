#pragma once
#include"Node.h"
#include<string>
using namespace std;
class Gate
{
protected:
	int n;   //n number of inputs 
	int N = n + 1; // N number of Nodes N=n+1
	Node* p;
	Node o;
	string type;
public:
	Gate();
	/*	~Gate();
	Gate(const Gate& b) ;/**/
	void settype(string);
	string gettype();
	int getinputNumber();
	void setinputNumber(int);
	void setinputvalue(int, bool);
	void setinputname(string, int);
	bool getinputvalue(string);
	string getinputname(int);
	void setoutput(bool);
	bool getoutput();
	void setoutputname(string);
	string getoutputname();
};

