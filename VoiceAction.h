#include "Actions/Action.h"
#include "ApplicationManager.h"
#pragma once
class VoiceAction :public Action{

public:
	VoiceAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute();
};