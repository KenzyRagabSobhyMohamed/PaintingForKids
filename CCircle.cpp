#include "CCircle.h"
#include "Figures/CFigure.h"


CCircle::CCircle()
{
	type = 'c';
}

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Radu = P2;
	Radius = sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2));
	type = 'c';
}

void CCircle::Draw(Output* pOut) const
{
	pOut->DrawCircle(Center, Radu, FigGfxInfo, Selected);

}

bool CCircle::IsInside(int x,int y)const
{
	//Creates a point P(x,y) to use in CalcDistance
	Point P;
	P.x = x;
	P.y = y;
	//to check if the point in the circle wa check the distance between center and the point if it is within the range
	return (Radius >= CalcDistance(Center, P));
}
void CCircle::PrintInfo(Output* pOut) const {
	//Forming the printed message string then passing it to PrintMessage
	string message = "Circle, ID: " + to_string(ID) + ", Center (" + to_string(Center.x) + "," + to_string(Center.y)
		+ "), Radius: " + to_string(int(Radius));
	pOut->PrintMessage(message);
}

void CCircle::Save(ofstream& OutFile)
{
	OutFile << "CIRC" << "  \t  " << to_string(ID) << "  \t " << to_string(Center.x) << "  \t  " << to_string(Center.y) << " \t   " << to_string(Radius) << "  \t " << GetColorname(FigGfxInfo.DrawClr) << " \t "<< GetColorname(FigGfxInfo.FillClr) << "\n";
}
void CCircle::Load(ifstream& Infile)
{
	int ID;
	Point Center;
	int Radius;
	GfxInfo FigGfxInfo;
	string s;
	color x;
	Infile >> ID >> Center.x >> Center.y >> Radius;
	Infile >> s;
	if (s == "BLACK")
		x= BLACK;
	else if (s == "BLUE")
		x= BLUE;
	else if (s == "ORANGE")
		x= ORANGE;
	else if (s == "RED")
		x= RED;
	else if (s == "YELLOW")
		x= YELLOW;
	else if (s == "GREEN")
		x= GREEN;
	else
		x= BLACK;
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