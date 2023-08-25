#pragma once
#include "Actions/Action.h"
#include "Figures/CFigure.h"
#include<fstream>
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
class LoadAction:public Action
{
protected:
	Output* pOut;
	Input* pIn;
	GfxInfo c;
	color f;
	color d;
	ifstream fin;
	string name;
	CFigure* fig;
public:
	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	color getcolor(string s);
	virtual void Execute();

};

