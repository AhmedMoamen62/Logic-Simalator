#include "OR.h"
OR::OR()
{
	o.setValue(0);
}
OR OR::operator = (Gate a)
{
	OR x;
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
void OR::setoutput()
{
	for (int i = 0; i < n; i++)
	{
		if (p[i].getValue() == 1)
		{
			o.setValue(1);
			break;
		}
	}
}