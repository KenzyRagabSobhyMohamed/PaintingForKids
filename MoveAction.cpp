/*#include "MoveAction.h"
#include"Actions/Action.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include <fstream>
#include "Figures/CFigure.h"
#include "ApplicationManager.h"
#include "SaveAction.h"
#include "LoadAction.h"
#include "CHexagon.h"
#include "CCircle.h"
#include "CSquare.h"
#include "CTriangle.h"
#define ADD_RECT_ACTION_H


MoveAction::MoveAction(ApplicationManager* pApp) :Action(pApp) {}

void MoveAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();   //Get a pointer to the Output class
	Input* pIn = pManager->GetInput();     //Get a pointer to Input Class

	Selecfigur = pManager->GetSelectedFigures();
	count = pManager->GetSelectedCount();

	if (Selecfigur[0] == NULL)
		selected = false;
	else
		selected = true;
	pOut->PrintMessage("Pick Second Location");
	pIn->GetPointClicked(p1.x, p1.y);
	pOut->ClearStatusBar();
}

void MoveAction::CalcNew() {
	ReadActionParameters();
	if (selected) {
		for (int i = 0; i < pManager->GetSelectedCount(); i++) {
			if (Selecfigur[i]->gettype() == 'r') {
				AddRecActio
			}
		}
	}

}

void MoveAction::Draw(){}

void MoveAction::Execute() {

}


	MoveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	void CalcNew(Point);
	void Draw();
	virtual void Execute();
*/