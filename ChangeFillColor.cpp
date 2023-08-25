#include "ChangeFillColor.h"
#include "Actions/Action.h"
#include "Figures/CFigure.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "UndoAction.h"
ChangeFillColor::ChangeFillColor(ApplicationManager* pApp) : Action(pApp)
{}
void  ChangeFillColor::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	pOut->PrintMessage("choose the fill color you want");
	Selecfigur = pManager->GetSelectedFigures();
	count = pManager->GetSelectedCount();

	//know if the figure is selected or not
	if (!pManager->GetColor(fillcolor))

		Color = false;
	else
		Color = true;

	if (Selecfigur[0] == NULL)
		selected = false;
	else
		selected = true;


	
	pOut->ClearStatusBar();


}

void ChangeFillColor::Execute()
{
	ReadActionParameters();
	if (Color)
	{
		if (selected)
		{
			for (int i = 0; i < count; i++)
			{
				Selecfigur[i]->ChngFillClr(fillcolor);

			}
		}
		else
		{
			pOut->setIsfilled(true);
			pOut->setCrntFillColor(fillcolor);
		}


	}
	UndoAction u(pManager);
	u.SaveState();
}
