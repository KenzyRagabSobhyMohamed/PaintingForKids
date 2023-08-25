#include "Actions/Action.h"
#include "Figures/CFigure.h"
#include "DEFS.h"
#pragma once
class pckcoloraction :public Action
{
protected:
	Point p1, p2;
	int rc, blc, yc, oc, gc, bc;
	CFigure* list[200];
	GfxInfo graphics[200];
	int q;

public:

	pckcoloraction(ApplicationManager* pApp);
	void ReadActionParameters();
	void picks(color k, int size);
	void Execute();
};
