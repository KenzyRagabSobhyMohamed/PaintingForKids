#include "switchaction.h"
#include "ApplicationManager.h"

switchaction::switchaction(ApplicationManager* pApp) :Action(pApp)
{

}

void switchaction::Execute()
{
	Output* pOut = pManager->GetOutput();
	
	
		pOut->PrintMessage("switching to play mode.");
		pOut->ClearDrawArea2();
		pOut->CreatePlayToolBar();
		UI.InterfaceMode == MODE_PLAY;
	
}

void switchaction::ReadActionParameters()
{

}

switchaction::~switchaction()
{}