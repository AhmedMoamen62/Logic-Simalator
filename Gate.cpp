#include "Gate.h"
Gate::Gate()
{
	n = 2;
	N = n + 1;
	p = new Node[N];
	p[N - 1] = o;
	type = " ";
}
/*Gate::~Gate()
{
if (type != " ")
{
delete[]p;
}
}
Gate::Gate(const Gate& b)
{
n = b.n;
N = b.N;
type = b.type;
o = b.o;
if (type != " ")
{
p = new Node[N];
for (int i = 0; i < N; i++)
{
p[i] = b.p[i];
}
}
else
{
type = " ";
}
}/**/
string Gate::getoutputname()
{
	return o.getName();
}
void Gate::setoutputname(string a)
{
	o.setName(a);
	p[N - 1] = o;
}
bool Gate::getinputvalue(string t)
{
	for (int i = 0; i < N; i++)
	{
		if (t == getinputname(i + 1))
		{
			return p[i].getValue();
		}
	}
}
bool Gate::getoutput()
{
	return o.getValue();
}
string Gate::getinputname(int m)
{
	return p[m - 1].getName();
}
int Gate::getinputNumber()
{
	return n;
}
void Gate::setinputname(string m, int t)
{
	p[t - 1].setName(m);
}
string Gate::gettype()
{
	return type;
}
void Gate::settype(string u)
{
	type = u;
}
void Gate::setinputNumber(int m)
{
	if (m != 2)
	{
		n = m;
		N = n + 1;
		p = new Node[N];
		p[N - 1] = o;
		return;
	}
	return;
}
void Gate::setinputvalue(int m, bool c)
{
	p[m - 1].setValue(c);
}

void Gate::setoutput(bool a)
{
	o.setValue(a);
	p[N - 1] = o;
}