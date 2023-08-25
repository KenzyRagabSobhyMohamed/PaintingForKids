#pragma once
#include"Actions/Action.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include<fstream>
#include "Figures/CFigure.h"
#include "ApplicationManager.h"
#include "SaveAction.h"
#include "LoadAction.h"
class RedoAction:public Action{
	ifstream fin1, fin2;
	ofstream fout1, fout2;
	string Name[5];
	CFigure* fig;
	Output* pOut;
	Input* pIn;
	int index = 4;
public:
	RedoAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	string getClrname(color b);
	color getClrnamec(string s);
	virtual void Execute();
};

