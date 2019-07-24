#include "XNOR.h"
XNOR::XNOR()
{
	o.setValue(1);
}
void XNOR::setoutput()
{
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (p[i].getValue() == 1)
		{
			j++;
		}
	}
	if (j % 2 != 0)
	{
		o.setValue(0);
	}
}
XNOR XNOR::operator = (Gate a)
{
	XNOR x;
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