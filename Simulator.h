#pragma once
#include<iostream>
#include<fstream>
#include"Gate.h"
#include"Dynamicstring.h"
using namespace std;
class Simulator
{
	Dynamicstring s;
	Gate* design;
	int g_number = 0;
	int i_number = 0;
public:
	Simulator();
	void loopsim(string);
	void handlegates();
	void handleinp();
	void handleout();
	void printout(ifstream&);
};
string gatedetector(string);
int inputdetector(string);
bool boolconverter(string);
string getoutputname(string);

