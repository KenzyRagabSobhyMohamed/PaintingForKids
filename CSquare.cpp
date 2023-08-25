#include "CSquare.h"

CSquare::CSquare()
{
	type = 's';
}

CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	type = 's';
	center = P1;
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSqu to draw a square on the screen	
	pOut->DrawSqu(center, FigGfxInfo, Selected);
}
//bool CSquare::IsInside(Point P)
//{
//	int x1 = center.x - 60;
//	int x2 = center.x + 60;;
//	int y1 = center.y - 60;
//	int y2 = center.y + 60;
//
//	if (P.x >= x1 && P.x <= x2 && P.y >= y1 && P.y <= y2) {
//		SetSelected(!Selected);
//		return true;
//	}
//	return false;
//}

bool CSquare::IsInside(int x, int y) const {

	//Checks if the x & y coordinates lie inside/on the rectangle
	return ((x >= center.x-60 && x <= center.x+60)) && ((y >= center.y - 60 && y <= center.y + 60));
		
}



void CSquare::PrintInfo(Output* pOut) const {
	//Forming the printed message string then passing it to PrintMessage
	string message = "Square, ID: " + to_string(ID) + ", Center (" + to_string(center.x) + "," + to_string(center.y)
		;
	pOut->PrintMessage(message);
}
void CSquare::Save(ofstream& OutFile)
{
	OutFile << "SQUA" << " \t " << to_string(ID) << " \t " << to_string(center.x) << "  \t " << to_string(center.y) << "  \t " << GetColorname(FigGfxInfo.DrawClr) << " \t "<< GetColorname(FigGfxInfo.FillClr) << "\n";
	
}
void  CSquare::Load(ifstream& Infile)
{
	string s;
	int ID;
	Point center;
	color x;
	Infile >> ID >> center.x >> center.y;
	Infile >> s;
	if (s == "BLACK")
		x = BLACK;
	else if (s == "BLUE")
		x = BLUE;
	else if (s == "ORANGE")
		x = ORANGE;
	else if (s == "RED")
		x = RED;
	else if (s == "YELLOW")
		x = YELLOW;
	else if (s == "GREEN")
		x = GREEN;
	else
		x = BLACK;
	FigGfxInfo.DrawClr = x;
	Infile >> s;
	if (s == "NON-FILLED")
		FigGfxInfo.isFilled = false;
	else
	{
		FigGfxInfo.FillClr = x;
		FigGfxInfo.isFilled = true;
	}





 }