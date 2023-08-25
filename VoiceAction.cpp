#include "VoiceAction.h"
#include "ApplicationManager.h"


VoiceAction::VoiceAction(ApplicationManager* pApp) :Action(pApp)
{

}

void VoiceAction::ReadActionParameters()
{
}


void VoiceAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("voice activation changed");
	pManager->chvoice();
}