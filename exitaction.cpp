#include "ApplicationManager.h"
#include "exitaction.h"
exitaction::exitaction(ApplicationManager* pApp) : Action(pApp)
{

}




void exitaction::ReadActionParameters()
{

}


void exitaction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("click once again to exit");
	pIn->GetPointClicked(p1.x, p1.y);
}

exitaction::~exitaction()
{

}