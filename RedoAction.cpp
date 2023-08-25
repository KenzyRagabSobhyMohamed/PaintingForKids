#include "RedoAction.h"
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

RedoAction::RedoAction(ApplicationManager* pApp) :Action(pApp) {
	Name[0] = "Temp1.txt";
	Name[1] = "Temp2.txt";
	Name[2] = "Temp3.txt";
	Name[3] = "Temp4.txt";
	Name[4] = "Temp5.txt";
}
void RedoAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();   //Get a pointer to the Output class
	Input* pIn = pManager->GetInput();     //Get a pointer to Input Class
}

color RedoAction::getClrnamec(string s)
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
string RedoAction::getClrname(color b)
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
		return "No Color";
}

void RedoAction::Execute() {
	ReadActionParameters();
	string Test1;
	string drawcolor;
	string fillcolor;
	fout1.open("Temp");
	if (fout1.is_open()) {
		fillcolor = getClrname(UI.FillColor);
		drawcolor = getClrname(UI.DrawColor);

		fout1 << drawcolor << "  \t  " << fillcolor << "\n";
		fout1 << pManager->getFigCount() << endl;
		pManager->SaveAll(fout1);
		fout1.close();
	}
	fin2.open("Temp");
	if (fin2.is_open()) {
		while (fin2.good()) {
			fin2 >> Test1;
		}
	}
	fin2.close();
	pManager->UpdateInterface();
	for (int i = 4; i >= 0; i--) {
		string Test2;
		fin1.open(Name[i]);
		if (fin1.is_open()) {
			while (fin1.good()) {
				fin1 >> Test2;
			}
		}
		fin1.close();
		if (Test1 == Test2) {
			if (i == 4) {
				index = i;
				break;
			}
			index = i + 1;
			break;
		}
		
	}
	ReadActionParameters();
	int Count;
	string myname, DrawColor, FillColor;
	fin2.open(Name[index]);
	fin2 >> DrawColor >> FillColor;
	UI.DrawColor = getClrnamec(DrawColor);  //Convert them
	UI.FillColor = getClrnamec(FillColor);
	pManager->ClearFigList(); //clear figlist
	fin2 >> Count; // read the number of figures
	fig = NULL;
	for (int i = 0; i < Count; i++)
	{
		fin2 >> myname;
		//if (myname == "RECT")
		   // fig = new CRectangle;
		if (myname == "CIRC")
			fig = new CCircle;
		else if (myname == "TRIANG")
			fig = new CTriangle;
		else if (myname == "HEX")
			fig = new CHexagon;
		else if (myname == "SQUA")
			fig = new CSquare;

		fig->Load(fin2);
		pManager->AddFigure(fig); //Add to the figure list
	}
	pManager->UpdateInterface();
	pOut->ClearStatusBar();
}

/*
	RedoAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	color getClrnamec(string s);
	virtual void Execute();
*/
