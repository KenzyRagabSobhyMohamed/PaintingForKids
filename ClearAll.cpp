#include "ClearAll.h"
#include "UndoAction.h"

ClearAll::ClearAll(ApplicationManager* pApp) :Action(pApp)
{}
void ClearAll::ReadActionParameters()
{
	pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
}
void ClearAll::Execute()
{
	ReadActionParameters();
	pManager->ClearFigList();
	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
	UndoAction u(pManager);
	u.SaveState();
	
}