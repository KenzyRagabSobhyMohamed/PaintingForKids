#pragma once

#include "Actions/Action.h"
#include<fstream>

class StartRecAction :public Action
{
private:
	ofstream OutFile;
	int SelectedFigcount;
	int Operation = 0;

public:
	StartRecAction(ApplicationManager* pApp);

	//Reads select parameters
	virtual void ReadActionParameters();

	//Executes the select action
	virtual void Execute();

};
