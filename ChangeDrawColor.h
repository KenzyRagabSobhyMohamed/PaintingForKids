#pragma once
#include "Actions/Action.h"
#include "Figures/CFigure.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
	class ChangeDrawColor :public Action
{
protected:
	bool selected;
	bool Color;
	CFigure* const* Selecfigur;// make array 
	color drawcolor;
	Output* pOut;
	Input* pIn;
public:
	ChangeDrawColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};


