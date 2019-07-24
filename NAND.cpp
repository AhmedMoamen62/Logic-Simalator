#include "NAND.h"
NAND::NAND()
{
	o.setValue(0);
}
void NAND::setoutput()
{
	for (int i = 0; i < n; i++)
	{
		if (p[i].getValue() == 0)
		{
			o.setValue(1);
			break;
		}
	}
}
NAND NAND::operator = (Gate a)
{
	NAND x;
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
