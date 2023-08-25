#pragma once
#include "GUI\input.h"
#include "GUI\Output.h"
#include "Figures/CFigure.h"
#include<fstream>
#include <iostream>
class CCircle : public CFigure
{
private:
	Point Center;
	Point Radu;
	int Radius;
	Output* pOut;
	Input* pIn;

public:
	CCircle();
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(int , int  )const;
	virtual void PrintInfo(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};


