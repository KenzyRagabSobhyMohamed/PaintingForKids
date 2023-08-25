#ifndef CRECT_H
#define CRECT_H

#include"Figures/CFigure.h"

class CSquare : public CFigure
{
private:
	Point center;
	Output* pOut;
public:
	CSquare();
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(int , int )const;
	virtual void PrintInfo(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};

#endif
