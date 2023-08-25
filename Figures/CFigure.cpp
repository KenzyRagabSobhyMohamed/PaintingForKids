#include "CFigure.h"

CFigure::CFigure()
{
	Selected = false;
}

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

char CFigure::gettype()
{
	return type;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
double CFigure::CalcDistance(Point A, Point B) const {
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
GfxInfo CFigure::GetGfxInfo() const
{
	return FigGfxInfo;
}
string CFigure::GetColorname(color c) 
{
	if (c == BLACK) 
		return "BLACK";
	else if (c == BLUE) 
		return "BLUE";
	else if (c == RED)
		return "RED";
	else if (c == YELLOW) 
		return "YELLOW";
	else if (c == GREEN) 
		return "GREEN";
	else if (c == ORANGE)
		return "ORANGE";
	else
	return "NO COLOR";
}
color  CFigure::GetColor(string s)
{
	if (s == "BLACK")
		return BLACK;
	else if (s == "BLUE")
		return BLUE;
	else if (s == "ORANGE")
		return ORANGE;
	else if (s == "RED")
		return RED;
	else if (s == "YELLOW")
		return YELLOW;
	else if (s == "GREEN")
		return GREEN;
	else
	return BLACK;
}
void CFigure::SetID(int id)
{
	ID = id;
}

//Gets the figure ID

int CFigure::GetID() const
{
	return ID;
}
void CFigure::SaveByID(ofstream& Outfile, int id)
{

	Outfile << "-1" << "\t" << id << endl;
}