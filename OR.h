#pragma once
#include "Gate.h"
class OR : public Gate
{
public:
	OR();
	void setoutput();
	OR operator = (Gate a);
};
