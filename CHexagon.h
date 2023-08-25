#pragma once

#include "Figures/CFigure.h"

class CHexagon : public CFigure
{
private:
	Point center;
	GfxInfo C;
	Output* pOut;
public:
	CHexagon();
	CHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool CHexagon::IsInside(int ,int )const;
	virtual void PrintInfo(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};

