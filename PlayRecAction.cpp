#include "PlayRecAction.h"
#include "LoadAction.h"
#include "CHexagon.h"
#include "CCircle.h"
#include "CSquare.h"
#include "CTriangle.h"
#include "Figures/CRectangle.h"
#include"fstream"

PlayRecAction::PlayRecAction(ApplicationManager* pApp) :Action(pApp)
{}
void PlayRecAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();   //Get a pointer to the Output class
	Input* pIn = pManager->GetInput();     //Get a pointer to Input Class
}
color PlayRecAction::Getcolor(string s)
{
	if (s == "BLACK")
		return BLACK;
	else if (s == "BLUE")
		return BLUE;
	else if (s == "RED")
		return RED;
	else if (s == "YELLOW")
		return YELLOW;
	else if (s == "GREEN")
		return GREEN;
	else if (s == "ORANGE")
		return ORANGE;
	else
		return BLACK;
}

void  PlayRecAction::Execute()
{
	ReadActionParameters();
	int Count;
	string myname, DrawColor, FillColor;
	fin.open("Record.txt");
	fin >> DrawColor >> FillColor;
	UI.DrawColor = Getcolor(DrawColor);  //Convert them
	UI.FillColor = Getcolor(FillColor);
	pManager->ClearFigList(); //clear figlist
	fin >> Count; // read the number of figures
	for (int i = 0; i < Count; i++)
	{
		fin >> myname;
		//if (myname == "RECT")
		   //fig = new CRectangle;
		if (myname == "CIRC")
			fig = new CCircle;
		else if (myname == "TRIANG")
			fig = new CTriangle;
		else if (myname == "HEX")
			fig = new CHexagon;
		else if (myname == "SQUA")
			fig = new CSquare;

		fig->Load(fin);
		pManager->AddFigure(fig); //Add to the figure list
	}
	pManager->UpdateInterface();
}