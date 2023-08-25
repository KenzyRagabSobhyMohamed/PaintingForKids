#pragma once
#include "Actions/Action.h"
#include "Figures/CFigure.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
class ChangeFillColor :public Action
{
protected:
	bool selected;
	bool Color;
	int count;
	GfxInfo x;
	CFigure* const* Selecfigur;// make array 
	color fillcolor;
	Output* pOut;
	Input* pIn;
public:
	ChangeFillColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};



