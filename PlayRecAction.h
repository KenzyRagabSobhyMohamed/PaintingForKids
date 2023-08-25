#pragma once
#include"Actions/Action.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include<fstream>
#include "Figures/CFigure.h"
#include "ApplicationManager.h"
#include "SaveAction.h"
#include "LoadAction.h"
class PlayRecAction:public Action{
	Output* pOut;
	Input* pIn;
	GfxInfo c;
	color f;
	color d;
	ifstream fin;
	string name;
	CFigure* fig;
public:
	PlayRecAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	color Getcolor(string s);
	virtual void Execute();

};

