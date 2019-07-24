#include "Simulator.h"
#include"AND.h"
#include"OR.h"
#include"NAND.h"
#include"NOT.h"
#include"XOR.h"
#include"XNOR.h"
#include"NOR.h"
Simulator::Simulator()
{
	design = NULL;
	g_number = 0;
	i_number = 0;
}
void Simulator::loopsim(string filename)
{
	ifstream f;
	f.open(filename);
	while (!f.eof())
	{
		string t;
		getline(f, t);
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
			break;
		}
	}
	design = new Gate[g_number];
	handlegates();
	handleinp();
	handleout();
	printout(f);
	f.close();
}
string gatedetector(string a)
{
	int m = a.find(' ');
	string z = a.substr(0, m);
	return z;
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
bool boolconverter(string z)
{
	int t = z.length();
	if (z[t - 1] == '1')
	{
		return 1;
	}
	if (z[t - 1] == '0')
	{
		return 0;
	}
}
string getoutputname(string z)
{
	for (int i = z.length() - 1; i > 0; i--)
	{
		if (z[i] == ' ')
		{
			return z.substr(i + 1);
		}
	}
}
void Simulator::handlegates()
{
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
}
void Simulator::handleinp()
{
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
}
void Simulator::handleout()
{
	for (int i = 0; i < g_number; i++)
	{
		string m = design[i].gettype();
		if (m == "AND")
		{
			AND x, y;
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
		if (m == "XOR")
		{
			XOR x, y;
			y = x = design[i];
			y.setoutput();
			design[i].setoutput(y.getoutput());
		}
		if (m == "NAND")
		{
			NAND x, y;
			y = x = design[i];
			y.setoutput();
			design[i].setoutput(y.getoutput());
		}
		if (m == "XNOR")
		{
			XNOR x, y;
			y = x = design[i];
			y.setoutput();
			design[i].setoutput(y.getoutput());
		}
		if (m == "NOR")
		{
			NOR x, y;
			y = x = design[i];
			y.setoutput();
			design[i].setoutput(y.getoutput());
		}
		if (i != g_number - 1)
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
}
void Simulator::printout(ifstream& e)
{
	while (!e.eof())
	{
		string t[2];
		e >> t[0] ;
		if (t[0] == "OUT")
		{
			e >> t[1];
			if (t[1] == "ALL")
			{
				for (int i = 0; i < g_number; i++)
				{
					cout << design[i].getoutputname() << " = " << design[i].getoutput() << endl;
				}
			}
			else
			{
				for (int i = 0; i < g_number; i++)
				{
					if (t[1] == design[i].getoutputname())
					{
						cout << design[i].getoutputname() << " = " << design[i].getoutput() << endl;
						break;
					}
				}
			}
		}
	}
}
