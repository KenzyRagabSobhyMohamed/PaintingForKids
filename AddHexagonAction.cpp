#include "AddHexagonAction.h"
#include "CHexagon.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "UndoAction.h"

AddHexagonAction::AddHexagonAction(ApplicationManager* pApp) : Action(pApp)
{}

void AddHexagonAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New hexagon: Click at the center");

	//Read 1st center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);


	HexGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexagonAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a triangle with the parameters read from the user
	CHexagon* H = new CHexagon(P1, HexGfxInfo);

	//Add the triangle to the list of figures
	pManager->AddFigure(H);
	UndoAction u(pManager);
	u.SaveState();
}



