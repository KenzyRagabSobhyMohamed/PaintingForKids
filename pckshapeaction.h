#include "Actions/Action.h"
#include "Figures/CFigure.h"
#include "DEFS.h"
#pragma once


class pckshapeaction : public Action
{
protected:
	CFigure* arr[200];//array of all figures
	Point p1;
	Point p2;
	CFigure* rect[200];
	CFigure* tri[200];
	CFigure* hex[200];
	CFigure* sqa[200];
	CFigure* cir[200];




	//counters for each shape
	int r;
	int s;
	int c;
	int h;
	int t;

public:

	pckshapeaction(ApplicationManager* pApp);
	void picks(CFigure* k[], char id, int size);
	void ReadActionParameters();
	void Execute();
};