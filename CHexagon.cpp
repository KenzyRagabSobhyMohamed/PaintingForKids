#include "CHexagon.h"
CHexagon::CHexagon()
{
	type = 'h';
}
CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P1;
	type = 'h';
}


void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHexa to draw a square on the screen	
	pOut->DrawHexagon(center, FigGfxInfo, Selected); 
}

bool CHexagon::IsInside(int x, int y)const
{
	
		//Creates a point P(x,y) to use in CalcDistance
		Point P;
		P.x = x;
		P.y = y;
		//to check if the point in the circle wa check the distance between center and the point if it is within the range
		return (150>= CalcDistance(center, P));
}
void CHexagon::PrintInfo(Output* pOut) const 
{
	//Forming the printed message string then passing it to PrintMessage
	string message = "hexagon, ID: " + to_string(ID) + ", Center (" + to_string(center.x) + "," + to_string(center.y)
		;
	pOut->PrintMessage(message);
}
void  CHexagon::Save(ofstream& OutFile)
{
	OutFile << "HEX" << "  \t " << to_string(ID) << " \t " << to_string(center.x) << " \t  " << to_string(center.y) << "  \t " << GetColorname(FigGfxInfo.DrawClr) << " \t"<< GetColorname(FigGfxInfo.FillClr) << "\n";

}
 void  CHexagon::Load(ifstream& Infile)
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