#pragma once
#include"Figures/CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
	Output* pOut;
public:
	CTriangle();
	CTriangle(Point, Point,Point, GfxInfo FigureGfxInfo);
	float Area(int, int, int, int, int, int) const;
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(int , int )const;
	virtual void PrintInfo(Output* pOut) const;
	bool isOnBorder(Point, Point, Point) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};

