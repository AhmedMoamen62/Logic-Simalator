#pragma once
#include "Gate.h"
class NOT : public Gate
{
public:
	NOT();
	void setoutput();
	NOT operator = (Gate a);
};

