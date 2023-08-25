#include "AddSquareAction.h"
#include "CSquare.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"
#include "UndoAction.h"

AddSquareAction::AddSquareAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSquareAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New square: Click at the center");

	//Read center point P1
	pIn->GetPointClicked(P1.x, P1.y);

	

	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddSquareAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Square with the parameters read from the user
	CSquare* R = new CSquare(P1, RectGfxInfo);

	//Add the Square to the list of figures
	pManager->AddFigure(R);
	UndoAction u(pManager);
	u.SaveState();
}

