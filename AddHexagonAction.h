#pragma once
#include "Actions/Action.h"
//add hex action class
class AddHexagonAction:public Action
{
private:
	Point P1; //hexagon center
	GfxInfo HexGfxInfo;
public:
	AddHexagonAction(ApplicationManager* pApp);

	//Reads hexagon parameters
	virtual void ReadActionParameters();

	//Add square to the ApplicationManager
	virtual void Execute();

};


