#pragma once
#include "Gate.h"
class XNOR : public Gate
{
public:
	XNOR();
	void setoutput();
	XNOR operator = (Gate a);
};
