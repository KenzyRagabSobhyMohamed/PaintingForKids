#include "ChangeDrawColor.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
ChangeDrawColor::ChangeDrawColor(ApplicationManager* pApp) :Action(pApp)
{}
void ChangeDrawColor::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	pOut->PrintMessage("choose the draw color you want");
	Selecfigur = pManager->GetSelectedFigures();
	//know if the figure is selected or not
	if (!pManager->GetColor(drawcolor))

		Color = false;
	else
		Color = true;

	if (Selecfigur[0] == NULL)
		selected = false;
	else
		selected = true;

	//Read clicked point and store in P
	pOut->ClearStatusBar();
}

void ChangeDrawColor::Execute()
{
	pOut = pManager->GetOutput();
	ReadActionParameters();
	if (Color)
	{
		pOut->setCrntDrawColor(drawcolor);
	}
}