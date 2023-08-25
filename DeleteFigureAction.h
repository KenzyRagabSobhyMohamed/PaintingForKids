#pragma once
#include "Actions/Action.h"
#include "Figures/CFigure.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
	class DeleteFigureAction :public Action
{
protected:

	Output* pOut;
	Input* pIn;
	CFigure* selectedfigures;
	CFigure* const* Selecfigur;
	int count;
	bool selected;
public:
	DeleteFigureAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};


