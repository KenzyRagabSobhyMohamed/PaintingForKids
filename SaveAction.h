#pragma once
#include<fstream>
#include "Actions/Action.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "Figures/CFigure.h"
class SaveAction:public Action
{
protected:
	Output* pOut;
	Input* pIn;
	GfxInfo c;
	CFigure* n;
	color f;
	color d;
	ofstream fout;
	string name;
public:
	SaveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	string getClrname(color b);
	virtual void Execute();
};

