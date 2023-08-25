#pragma once

#include "Actions/Action.h"

//Add square Action class
class AddSquareAction : public Action
{
private:
	Point P1; //square center
	GfxInfo RectGfxInfo;
public:
	AddSquareAction(ApplicationManager* pApp);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Add square to the ApplicationManager
	virtual void Execute();

};
