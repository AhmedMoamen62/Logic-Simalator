#pragma once
#include "Gate.h"
class NAND : public Gate
{
public:
	NAND();
	void setoutput();
	NAND operator = (Gate a);
};

