#include "Node.h"
Node::Node()
{
	Name = " ";
	v = 0;
}
void Node::setName(string N)
{
	Name = N;
}
void Node::setValue(bool b)
{
	v = b;
}
bool Node::getValue()
{
	return v;
}
string Node::getName()
{
	return Name;
}
