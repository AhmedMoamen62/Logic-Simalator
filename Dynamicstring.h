#pragma once
#include<string>
using namespace std;
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
