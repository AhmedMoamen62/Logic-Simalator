#pragma once
#include<string>
using namespace std;
class Node
{
	string Name;
	bool v;
public:
	Node();
	void setName(string);
	void setValue(bool);
	bool getValue();
	string getName();
};
