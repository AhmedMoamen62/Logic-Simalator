#include <iostream>
#include <string>
using namespace std;
class Node
{
protected:
	string Name;
	bool v;
public:
	Node();
	void setName(string);
	void setValue(bool);
	bool getValue();
	string getName();
};
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
	~Gate();
	Gate(const Gate& b) ;
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
Gate::Gate()
{
	n = 2;
	N = n + 1;
	p = new Node[N];
	p[N - 1] = o;
	type = " ";
}
Gate::~Gate()
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
}
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
	if (m == 2)
	{
		__nop;
	}
	else
	{
		n = m;
		N = n + 1;
		p = new Node[N];
		p[N - 1] = o;
	}
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
class AND : public Gate
{
public:
	AND();
	void setoutput();
	AND operator = (Gate a);
};
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
		x.setinputname(a.getinputname(i + 1),i+1);
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
class OR : public Gate
{
public:
	OR();
	void setoutput();
	OR operator = (Gate a);
};
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
class NAND : public Gate
{
public:
	NAND();
	void setoutput();
};
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
class NOT : public Gate
{
public:
	NOT();
	void setoutput();
};
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
class XOR : public Gate
{
	XOR();
	void setoutput();
};
XOR::XOR()
{
	o.setValue(0);
}
void XOR::setoutput()
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
		o.setValue(1);
	}
}
class XNOR : public Gate
{
	XNOR();
	void setoutput();
};
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
class Dynamicstring
{
private:
	string* p;
	int n;
public:
	Dynamicstring()
	{
		n = 0;
		p = NULL;
	}
	void setsize(int m)
	{
		if (n == 0)
		{
			p = new string[m];
			n = m;
			return;
		}
		if (m < n)
		{
			string* t = new string[m];
			for (int i = 0; i < m; i++)
			{
				t[i] = p[i];
			}
			delete[]p;
			n = m;
			p = t;
			return;
		}
		if (m > n)
		{
			string* t = new string[m];
			for (int i = 0; i < n; i++)
			{
				t[i] = p[i];
			}
			delete[]p;
			n = m;
			p = t;
			return;
		}
	}
	string getel(int m)
	{
		return p[m - 1];
	}
	void add(string t)
	{
		setsize(n + 1);
		p[n - 1] = t;
	}
	void setel(int m, string s)
	{
		p[m - 1] = s;
	}
	~Dynamicstring()
	{
		if (p != NULL)
		{
			delete[]p;
		}
	}
	Dynamicstring(const Dynamicstring& d)
	{
		n = d.n;
		if (n > 0)
		{
			p = new string[n];
			for (int i = 0; i < n; i++)
			{
				p[i] = d.p[i];
			}
		}
		else
		{
			p = NULL;
		}
	}
};
int inputdetector(string);
string gatedetector(string);
bool boolconverter(string);
string getoutputname(string);
int main()
{
	int flag = 1;
	int g_number = 0;
	int i_number = 0;
	Dynamicstring s;
	cout << "Enter your Design" << endl;
	while (flag)
	{
		string t;
		getline(cin, t);
		if (t != "SEM")
		{
			s.add(t);
			if (gatedetector(t) != "SET")
			{
				g_number++;
			}
			else
			{
				i_number++;
			}
		}
		else
		{
			flag = 0;
			break;
		}
	}
	Gate* design = new Gate[g_number];
	for (int i = 0; i < g_number; i++) // set node name for each gate and set node and input number
	{
		int m = 1;
		string t = gatedetector(s.getel(i + 1));
		design[i].settype(t);
		string r = s.getel(i + 1);
		r = r.substr(r.find(' ') + 1);
		int gate_intput = inputdetector(s.getel(i + 1));
		design[i].setinputNumber(gate_intput);
		string y = r;
		for (int j = 0; j < r.length(); j++)
		{
			if (r[j] != ' ')
			{
				design[i].setinputname(y.substr(0, y.find(' ')), m);         // node name
				y = y.substr(y.find(' ') + 1);
				j = 0;
				if (m == gate_intput)
				{
					break;
				}
				else
				{
					m++;
				}
			}
		}
		design[i].setoutputname(getoutputname(r));
	}
	for (int i = g_number + 1; i < i_number + g_number + 1; i++) // to set values of Nodes
	{
		string t = s.getel(i);
		bool o = boolconverter(t);
		string r = t.substr(t.find(' ') + 1);
		r = r.substr(0, r.find(' '));
		for (int j = 0; j < g_number; j++)
		{
			int n = design[j].getinputNumber();
			for (int y = 0; y < n; y++)
			{
				if (r == design[j].getinputname(y + 1))
				{
					design[j].setinputvalue(y + 1, o);
				}
			}
		}
	}
	for (int i = 0; i < g_number; i++)
	{
		string m = design[i].gettype();
		if (m == "AND")
		{
			AND x,y;
			y = x = design[i];
			y.setoutput();
			design[i].setoutput(y.getoutput());
		}
		if (m == "OR")
		{
			OR x, y;
			y = x = design[i];
			y.setoutput();
			design[i].setoutput(y.getoutput());
		}
		if (i != g_number - 1 )
		{
			string t = design[i].getoutputname();
			bool u = design[i].getoutput();
			for (int j = 0; j < design[i + 1].getinputNumber(); j++)
			{
				if (t == design[i + 1].getinputname(j + 1))
				{
					design[i + 1].setinputvalue(j + 1, u);
				}
			}
		}
	}
	cout << design[1].getoutput() << endl;
	system("Pause");
}
int inputdetector(string t)
{
	int m = t.length();
	int j = 0;
	for (int i = 0; i < m; i++)
	{
		if (t[i] == ' ')
		{
			j++;
		}
	}
	return j - 1;
}
string gatedetector(string t)
{
	int m = t.find(' ');
	string s = t.substr(0, m);
	return s;
}
bool boolconverter(string s)
{
	int t = s.length();
	if (s[t - 1] == '1')
	{
		return 1;
	}
	if (s[t - 1] == '0')
	{
		return 0;
	}
}
string getoutputname(string s)
{
	for (int i = s.length() - 1; i > 0; i--)
	{
		if (s[i] == ' ')
		{
			return s.substr(i + 1);
		}
	}
}