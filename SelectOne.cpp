#include "SelectOne.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

SelectOne::SelectOne(ApplicationManager* pApp) :Action(pApp)
{}

void SelectOne::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut =pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a figure: Click a figure");

	//Read clicked point and store in P
	pIn->GetPointClicked(P.x, P.y);

	//Clear the status bar
	pOut->ClearStatusBar();
}

//Execute the action
void SelectOne::Execute()
{
	//Reads the point that the user clicked
	ReadActionParameters();

	//Set SelectedFig to the clicked figure (if any)
	SelectedFigure = pManager->GetFigure(P.x, P.y);

	//Checks if a figure was clicked, and whether the clicked figure is already selected
	if (SelectedFigure != NULL) {
		if (SelectedFigure->IsSelected())
			Unselect();
		else
			Select();
	}
}

//Selected an unselected figure
void SelectOne::Select() {
	pManager->unsel();
	SelectedFigure->SetSelected(true); //Sets the figure as "selected"
	pManager->AddSelectedFigure(SelectedFigure); //Add the figure to ApplicationManager's SelectedFigs array
	Output* pOut = pManager->GetOutput(); //Get a Pointer to the Output Interface
	SelectedFigure->PrintInfo(pOut); //Print the selected figure info on the status bar
}

//Unselect a selected figure
void SelectOne::Unselect() {
	SelectedFigure->SetSelected(false); //Sets the figure as "unselected"
	pManager->RemoveSelectedFigure(SelectedFigure);	//Removes the figure from ApplicationManager's SelectedFigs array
}