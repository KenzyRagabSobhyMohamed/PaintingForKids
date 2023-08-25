#include "switchdaction.h"
#include "ApplicationManager.h"

switchdaction::switchdaction(ApplicationManager* pApp) :Action(pApp)
{

}

void switchdaction::Execute()
{
	Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("switching to Draw mode.");
		pOut->ClearDrawArea2();
		pOut->CreateDrawToolBar();
		UI.InterfaceMode == MODE_DRAW;
}

void switchdaction::ReadActionParameters()
{

}

switchdaction::~switchdaction()
{}
