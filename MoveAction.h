/*#pragma once
#include"Actions/Action.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include<fstream>
#include "Figures/CFigure.h"
#include "ApplicationManager.h"
#include "SaveAction.h"
#include "LoadAction.h"
class MoveAction: public Action{
private:
	Point p1, p2;
	CFigure* Fig;
	CFigure* selectedfigures;
	CFigure* const* Selecfigur;
	int count;
	bool selected;
public:
	MoveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	void CalcNew();
	void Draw();
	virtual void Execute();
};*/

