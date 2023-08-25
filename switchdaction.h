#include "GUI/UI_Info.h"
#include "GUI/Output.h"
#include "GUI/Input.h"
#include "Actions/Action.h"
#pragma once
//switch to draw action
class switchdaction : public Action
{
public:
	switchdaction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
	~switchdaction();
};

