#pragma once
#include "Gate.h"
class AND : public Gate
{
public:
	AND();
	void setoutput();
	AND operator = (Gate a);
};

