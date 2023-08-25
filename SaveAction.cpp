#include "SaveAction.h"
#include "Actions/Action.h"
#include "Figures/CFigure.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

SaveAction::SaveAction(ApplicationManager* pApp):Action(pApp)
{}
void SaveAction::ReadActionParameters()
{

	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	pOut->PrintMessage("Enter The Name of Your file");
	name = pIn->GetSrting(pOut) + ".txt";
	pOut->ClearStatusBar();
}
string SaveAction::getClrname(color b)
{
	if (b == BLACK)
	return "BLACK";
	else if (b == BLUE)
		return  "BLUE";
	else if (b == RED)
		return "RED";
	else if (b == GREEN)
		return "GREEN";
	else if (b == YELLOW)
		return  "YELLOW";
	else if (b == ORANGE)
		return  "ORANGE";
	else
		return "no color";
}
void SaveAction::Execute()
{	
	ReadActionParameters();
	string drawcolor;
	string fillcolor;
	fout.open(name);
	if (fout.is_open())
	{
		fillcolor = getClrname(UI.FillColor);
		drawcolor = getClrname(UI.DrawColor);

		fout << drawcolor << "  \t  " << fillcolor << "\n";
		fout << pManager->getFigCount() << endl;
		pManager->SaveAll(fout);
		fout.close();
	}
	else
		pOut->PrintMessage("file can't open");
	pManager->UpdateInterface();
	pOut->ClearStatusBar();

}