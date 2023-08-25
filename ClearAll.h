#pragma once
#include "Actions/Action.h"
#include "Figures/CFigure.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
class ClearAll :public Action
{
protected:
	Output* pOut; ///pointer for class output
	Input* pIn; ///pointer for class intput

public:
	ClearAll(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};