#include "CRectangle.h"

CRectangle::CRectangle()
{
	type ='r';
}

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	type = 'r';
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::IsInside(int x, int y) const {

	//Checks if the x & y coordinates lie inside/on the rectangle
	return ((x >= Corner1.x && x <= Corner2.x) || (x <= Corner1.x && x >= Corner2.x))
		&& ((y >= Corner1.y && y <= Corner2.y) || (y <= Corner1.y && y >= Corner2.y));
}

void CRectangle::PrintInfo(Output* pOut) const {
	//Forming the printed message string then passing it to PrintMessage
	string message = "Rectangle, ID: " + to_string(ID) + ", Corner 1: (" + to_string(Corner1.x) + "," + to_string(Corner1.y)
		+ "), Corner 2: (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + "), Length: "
		+ to_string(abs(Corner1.x - Corner2.x)) + ", Width: " + to_string(abs(Corner1.y - Corner2.y));
	pOut->PrintMessage(message);
}
void CRectangle::Save(ofstream& OutFile)
{
	OutFile << " RECT" << " \t " << to_string(ID) << " \t" << to_string(Corner1.x) << "  \t " << to_string(Corner1.y) << "  \t " << to_string(Corner2.x) << "  \t " << to_string(Corner2.y) << "  \t " << to_string(abs(Corner1.x - Corner2.x)) << to_string(abs(Corner1.y - Corner2.y)) << "  \t " << GetColorname(FigGfxInfo.DrawClr) << " \t "<< GetColorname(FigGfxInfo.FillClr) << "\n";
}
void CRectangle::Load(ifstream& Infile)
{
	Point Corner1;
	Point Corner2;
	int ID;
	color x;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
	string s;
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