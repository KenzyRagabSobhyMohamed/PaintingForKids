#include "UndoAction.h"
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

UndoAction::UndoAction(ApplicationManager* pApp) :Action(pApp){
	Name[0] = "Temp1.txt";
	Name[1] = "Temp2.txt";
	Name[2] = "Temp3.txt";
	Name[3] = "Temp4.txt";
	Name[4] = "Temp5.txt";
}
void UndoAction::ReadActionParameters(){
	Output* pOut = pManager->GetOutput();   //Get a pointer to the Output class
	Input* pIn = pManager->GetInput();     //Get a pointer to Input Class
}
string UndoAction::getClrname(color b)
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
color UndoAction::getClrnamec(string s)
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

void UndoAction::SaveState() {
	if (index == 4) {
		for (int i = 0; i < 4; i++) {
			fin1.open(Name[i+1]);
			fout1.open(Name[i]);
			while (!fin1.eof()) {
				string text;
				getline(fin1, text);
				fout1 << text << endl;
			}
			fin1.close();
			fout1.close();
		}
		ReadActionParameters();
		string drawcolor;
		string fillcolor;
		fout1.open(Name[index]);
		if (fout1.is_open()) {
			fillcolor = getClrname(UI.FillColor);
			drawcolor = getClrname(UI.DrawColor);

			fout1 << drawcolor << "  \t  " << fillcolor << "\n";
			fout1 << pManager->getFigCount() << endl;
			pManager->SaveAll(fout1);
			fout1.close();
		}
		pManager->UpdateInterface();
		index++;
	}
	else {
		ReadActionParameters();
		string drawcolor;
		string fillcolor;
		while (1) {
			int length=0;
			fin1.open(Name[index]);
			while (fin1.get() != EOF) {
				length++;
			}
			fin1.close();
			if (length != 0) {
				index++;
			}
			else {
				break;
			}
			if (index == 4) {
				for (int i = 0; i < 4; i++) {
					fin1.open(Name[i + 1]);
					fout1.open(Name[i]);
					while (!fin1.eof()) {
						string text;
						getline(fin1, text);
						fout1 << text << endl;
					}
					fin1.close();
					fout1.close();
				}
				break;
			}
		}
		fout1.open(Name[index]);
		if (fout1.is_open()) {
			fillcolor = getClrname(UI.FillColor);
			drawcolor = getClrname(UI.DrawColor);

			fout1 << drawcolor << "  \t  " << fillcolor << "\n";
			fout1 << pManager->getFigCount() << endl;
			pManager->SaveAll(fout1);
			fout1.close();
		}
		pManager->UpdateInterface();
		index++;
	}
}
void UndoAction::Execute() {
	index--;
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
