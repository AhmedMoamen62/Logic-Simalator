#pragma once
#include "Gate.h"
class XOR : public Gate
{
public:
	XOR();
	void setoutput();
	XOR operator = (Gate a);
};

