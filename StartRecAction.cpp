#include "StartRecAction.h"
#include "ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI/output.h"
#include <set>


StartRecAction::StartRecAction(ApplicationManager* pApp) :Action(pApp)
{
}

void StartRecAction::ReadActionParameters()
{

}

void StartRecAction::Execute()
{
	int CurrentlyDrawnFigs = pManager->getFigCount();
	int CurrentlySelectedFigs = pManager->GetSelectedCount();
	Output* pOut = pManager->GetOutput();
	if (CurrentlyDrawnFigs != 0 || CurrentlySelectedFigs != 0)
	{
		pOut->PrintMessage("error: This Action only can be done after a ClearAll action  or when program start");
	}
	else
	{
		OutFile.open("Record.txt");
		pOut->PrintMessage("Recording in Progress , You have only 20 operation to record");



		ActionType Action;
		CFigure* const* SelectedFigs;
		int SelectedFigcount;
		CFigure* const* FigList;
		set<int> ids;
		CFigure* Fig;
		while (Operation < 20)
		{
			Action = pManager->GetUserAction();

			if (Action == DRAW_STOP) // User Clicks On Stop Rec Icon.
			{
				pOut->PrintMessage("Recording has been Stopped ");
				break;
			}
			else if (Action == DRAW_REC || Action == DRAW_SAVE || Action == DRAW_LOAD || Action == EXIT || Action == STATUS)
			{
				// donot count these action as  operations
				Operation--;
			}
			else if (Action == DRAW_SEL)
			{
				pManager->ExecuteAction(Action);
				pManager->UpdateInterface();
				do
				{

					Action = pManager->GetUserAction();
					if (Action != DRAW_SEL)
					{
						SelectedFigs = pManager->GetSelectedFigures();
						SelectedFigcount = pManager->GetSelectedCount();
						for (int i = 0; i < SelectedFigcount; i++)
						{
							ids.insert(SelectedFigs[i]->GetID());
						}
						if (Action == DRAW_DEL)
						{
							for (int i = 0; i < SelectedFigcount; i++)
							{
								SelectedFigs[i]->SaveByID(OutFile, SelectedFigs[i]->GetID());

							}
						}
					}
					pManager->ExecuteAction(Action);
					pManager->UpdateInterface();


				} while (Action == DRAW_SEL);

				// get the ids for the selected figs.

				if (Action == DRAW_PEN || Action == DRAW_FILL)
				{
					SelectedFigs = pManager->GetSelectedFigures();
					FigList = pManager->GetFigList();
					for (int i = 0; i < pManager->getFigCount(); i++)
					{
						int id = FigList[i]->GetID();
						if (ids.count(id) > 0) // id found
						{
							FigList[i]->Save(OutFile);

						}
					}
				}


			}
			else if (Action == DRAW_CIR || Action == DRAW_HEX || Action == DRAW_RECT ||
				Action == DRAW_SQU || Action == DRAW_TRI)
			{
				pManager->ExecuteAction(Action);
				Fig = pManager->GetLastFigure();
				if (Fig != NULL)
				{

					Fig->Save(OutFile);
				}
			}
			else
			{
				continue;
			}

			pManager->UpdateInterface();
			Operation++;
			pOut->PrintMessage("You Have done " + to_string(Operation) + " Operations , You can click stop anytime");

		}
		if (Operation == 20)
		{
			pOut->PrintMessage("You Have Reached 20 Operation ):");
		}


	}
	OutFile.close();


}


