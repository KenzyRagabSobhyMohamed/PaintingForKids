#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "SelectOne.h"
#include"AddCircleAction.h"
#include"AddHexagonAction.h"
#include"AddSquareAction.h"
#include"AddTriangleAction.h"
#include"Actions/AddRectAction.h"
#include "ChangeDrawColor.h"
#include "ChangeFillColor.h"
#include "DeleteFigureAction.h"
#include "SaveAction.h"
#include "LoadAction.h"
#include"ClearAll.h"
#include "StartRecAction.h"
#include "switchaction.h"
#include "pckbothaction.h"
#include "pckshapeaction.h"
#include "pckcoloraction.h"
#include "exitaction.h"
#include ".//switchdaction.h"
#include "UndoAction.h"
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include "VoiceAction.h"
#include "PlayRecAction.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;
	clipboardCount = 0;
	//Create an array of figure pointers and set them to NULL
	//and intialise SelectedFigs array to NULL
	for (int i = 0; i < MaxFigCount; i++) {
		FigList[i] = NULL;
		SelectedFigs[i] = NULL;
		Clipboard[i] = NULL;
	}
	//initialise selectedCount to 0
	selectedCount = 0;
	voiceactivation = true;

	pOut->PrintMessage("Welcome to a world of wonders ! (i.e colors and stuff)");
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
//Reads the input command from the user and returns the corresponding action type
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		//Figures' Drawing Actions//
	case DRAW_SQU:
		pAct = new AddSquareAction(this);
		if (voiceactivation == true)
		{
			PlaySound(TEXT("You picked a square.wav"), NULL, SND_SYNC);
		}
		break;

	case DRAW_RECT:
		pAct = new AddRectAction(this);
		if (voiceactivation == true)
		{
			PlaySound(TEXT("You picked A Rectang.wav"), NULL, SND_SYNC);
		}
		break;

	case DRAW_CIR:
		pAct = new AddCircleAction(this);
		if (voiceactivation == true)
		{
			PlaySound(TEXT("You picked A Circle.wav"), NULL, SND_SYNC);
		}
		break;

	case DRAW_TRI:
		pAct = new AddTriangleAction(this);
		if (voiceactivation == true)
		{
			PlaySound(TEXT("You picked A Triangle.wav"), NULL, SND_SYNC);
		}
		break;
	case DRAW_HEX:
		pAct = new AddHexagonAction(this);
		if (voiceactivation == true)
		{
			PlaySound(TEXT("You picked A Hexagon.wav"), NULL, SND_SYNC);
		}
		break;

	case DRAW_FIND_COLOR:
		pAct = new pckcoloraction(this);
		break;

	case DRAW_FIND_SHAPE:
		pAct = new pckshapeaction(this);
		break;


	case DRAW_HIDE_SEEK:
		pAct = new pckbothaction(this);
		break;

	case EXIT:
		pAct = new exitaction(this);
		break;

	case TO_PLAY:
		pAct = new switchaction(this);
		break;

	case TO_DRAW:
		pAct = new switchdaction(this);
		break;
		
	case DRAW_SEL:
		pAct = new SelectOne(this);
		break;
	case DRAW_PEN:
		pAct = new ChangeDrawColor(this);
		break;
	case DRAW_FILL:
		pAct = new ChangeFillColor(this);
		break;
	case DRAW_DEL:
		pAct = new DeleteFigureAction(this);
		break;
	case DRAW_SAVE:
		pAct = new SaveAction(this);
		break;
	case DRAW_LOAD:
		pAct = new LoadAction(this);
		break;
	case DRAW_CLEAR:
		pAct = new ClearAll(this);
		break;
	case DRAW_VOICE:
		pAct = new VoiceAction(this);
		break;
	case DRAW_REC:
		pAct = new StartRecAction(this);
		break;
	case DRAW_UNDO:
		pAct = new UndoAction(this);
		break;
	case DRAW_REDO:
		pAct = new UndoAction(this);
		break;
	case DRAW_PLAY:
		pAct = new PlayRecAction(this);
		break;
	case STATUS:	//a click on the status bar ==> no action
		return;

	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
void ApplicationManager::chvoice()
{
	if (voiceactivation) {
		voiceactivation = false;
		return;
	}
	voiceactivation = true;
	return;
}
bool ApplicationManager::GetColor(color& drawcolor)
{
	bool Color = true;

	ActionType x = pIn->GetUserAction();
	switch (x)
	{
	case DRAW_BLACK:
		drawcolor = BLACK;
		break;

	case DRAW_BLUE:
		drawcolor = BLUE;
		break;
	case DRAW_GREE:
		drawcolor = GREEN;
		break;
	case DRAW_RED:
		drawcolor = RED;
		break;
	case DRAW_YELL:
		drawcolor = YELLOW;
		break;
	case DRAW_ORAN:
		drawcolor = ORANGE;
		break;
	default:
		Color = false;
	}
	pOut->CreateDrawToolBar();
	return Color;
}


////////////////////////////////////////////////////////////////////////////////////

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//


//Transfer figures in FigList to playmode
CFigure* ApplicationManager::DrawnFigs(int i) const
{
	return FigList[i];
}
////////////////////////////////////////////////////////////////////////////////////
//Transfer FigCount to playmode to avoid unnessecary loops
int ApplicationManager::getFigCount() const
{
	return FigCount;
}
////////////////////////////////////////////////////////////////////////////////////
//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
	{
		FigList[FigCount] = pFig;
		FigList[FigCount]->SetID(FigCount);
		FigCount++;
	}
}
void ApplicationManager::Deletefigure(CFigure* pFig)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (pFig==FigList[i])
		{
			delete	FigList[i];
			FigList[i] = FigList[FigCount - 1];
			FigList[FigCount-1] = NULL;
			FigCount--;
			selectedCount--;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////
//Removes a figure from the list of figures by its ID , then sorts the array
void ApplicationManager::RemoveFig(int ID) {
	//Loops on all figures ,starting at the index of the deleted one, shifting them back 1 element and setting their ID
	for (int i = ID; i < FigCount - 1; i++) {
		FigList[i] = FigList[i + 1];
		FigList[i]->SetID(i);
	}
	//Reduce FigCount by 1 and nullify the extra pointer (used to point at the deleted figure)
	FigCount--;
	FigList[FigCount] = NULL;
}

////////////////////////////////////////////////////////////////////////////////////
//If a figure is found return a pointer to it.
//if this point (x,y) does not belong to any figure return NULL
CFigure* ApplicationManager::GetFigure(int x, int y) const
{

	for (int i = FigCount - 1; i >= 0; i--) {
	//if (FigList[i]->HiddenStatus() == false)
			if (FigList[i]->IsInside(x, y))
				return FigList[i];
	}
	return NULL;
}
////////////////////////////////////////////////////////////////////////////////////
//Deletes all figures and nullifies the FigList (used with load)
void ApplicationManager::ClearFigList()
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i] = NULL;
		FigCount = 0;
	}
	
	
}
void ApplicationManager::SaveAll(ofstream& OutFile)
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(OutFile);
	}


}


//==================================================================================//
//							Select Functions										//
//==================================================================================//

//Returns the number of selected figures
int ApplicationManager::GetSelectedCount() const {
	return selectedCount;
}
////////////////////////////////////////////////////////////////////////////////////
//Returns a pointer to SelectedFigs array
CFigure* const* ApplicationManager::GetSelectedFigures() const {
	return SelectedFigs;
}
CFigure* const* ApplicationManager::GetFigList()
{
		return FigList;
}

CFigure* ApplicationManager::GetLastFigure()
{
	return FigList[FigCount - 1];

}
///////////////////////////////////////////////////////////////////////////////////
//Adds a figure to the SelectedFigs array
void ApplicationManager::AddSelectedFigure(CFigure* sf) {

	SelectedFigs[selectedCount] = sf;
	selectedCount++;
}
////////////////////////////////////////////////////////////////////////////////////
//Removes a figure from the SelectedFigs array
void ApplicationManager::RemoveSelectedFigure(CFigure* sf) {

	for (int i = 0; i < selectedCount; i++) {
		if (SelectedFigs[i] == sf) {
			SelectedFigs[i] = SelectedFigs[selectedCount - 1];
			SelectedFigs[selectedCount - 1] = NULL;
			selectedCount--;
			return;
		}
	}
}

void ApplicationManager::ClearSelectedFigs() {
	for (int i = 0; i < selectedCount; i++)
	{
		SelectedFigs[i] = NULL;
	}
	selectedCount = 0;
}

void ApplicationManager::unsel()
{
	for (int i = 0; i < selectedCount; i++)
	{

		if (SelectedFigs[i] != NULL)
		{
			SelectedFigs[i]->SetSelected(false);

		}
		RemoveSelectedFigure(SelectedFigs[i]);
	}
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
	{
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}

// gets data of figures drawn to create game modes
void ApplicationManager::getfigdata(CFigure* arr[])
{
	for (int i = 0;i < 200;i++)
	{
		arr[i] = FigList[i];
	}
}

////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	ClearFigList();
	delete pIn;
	delete pOut;
}
