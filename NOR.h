#pragma once
#include "Gate.h"
class NOR : public Gate
{
public:
	NOR();
	void setoutput();
	NOR operator = (Gate a);
};
