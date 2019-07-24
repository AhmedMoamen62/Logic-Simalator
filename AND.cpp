#include "AND.h"
AND::AND()
{
	o.setValue(1);
}
AND AND::operator = (Gate a)
{
	AND x;
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
void AND::setoutput()
{
	for (int i = 0; i < n; i++)
	{
		if (p[i].getValue() == 0)
		{
			o.setValue(0);
			break;
		}
	}
}