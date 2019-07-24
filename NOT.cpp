#include "NOT.h"
NOT::NOT()
{
	n = 1;
	N = 2;
	p = new Node[N];
	o.setValue(0);
}
void NOT::setoutput()
{
	if (p[0].getValue() == 0)
	{
		o.setValue(1);
	}
}
NOT NOT::operator = (Gate a)
{
	NOT x;
	x.n = a.getinputNumber();
	x.setinputNumber(n);
	x.type = a.gettype();
	for (int i = 0; i < x.n; i++)
	{
		x.setinputvalue(i + 1, a.getinputvalue(a.getinputname(i + 1)));
		x.setinputname(a.getinputname(i + 1), i + 1);
	}
	x.setoutputname(a.getoutputname());
	return x;
}
