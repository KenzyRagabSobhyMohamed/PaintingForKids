#include "DeleteFigureAction.h"
#include "ApplicationManager.h"
#include "Figures/CFigure.h"
#include "UndoAction.h"
DeleteFigureAction::DeleteFigureAction(ApplicationManager* pApp) :Action(pApp)
{}
void DeleteFigureAction::ReadActionParameters()
{
	Selecfigur = pManager->GetSelectedFigures();
	count = pManager->GetSelectedCount();

	if (Selecfigur[0] == NULL)
		selected = false;
	else
		selected = true;


}
void DeleteFigureAction::Execute()
{
	ReadActionParameters();
	if (selected)
	{

		for (int i = 0; i < count; i++)
		{
			Selecfigur[i]->SetSelected(true);

		}
	}
	pManager->Deletefigure(Selecfigur[0]);
	UndoAction u(pManager);
	u.SaveState();
}
