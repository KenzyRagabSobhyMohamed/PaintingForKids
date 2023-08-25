#include "Actions/Action.h"
#include "Figures/CFigure.h"
#pragma once
class pckbothaction : public Action
{
private:
	int r, s, c, h, t;
	CFigure* arr[200];
	CFigure* rect[200];
	CFigure* tri[200];
	CFigure* hex[200];
	CFigure* sqa[200];
	CFigure* cir[200];
	Point p11;
	Point p12;
	int rrc, rblc, ryc, roc, rgc, rbc;
	int src, sblc, syc, soc, sgc, sbc;
	int crc, cblc, cyc, coc, cgc, cbc;
	int trc, tblc, tyc, toc, tgc, tbc;
	int hrc, hblc, hyc, hoc, hgc, hbc;
	GfxInfo graphicsr[200];
	GfxInfo graphicss[200];
	GfxInfo graphicsc[200];
	GfxInfo graphicst[200];
	GfxInfo graphicsh[200];
public:

	pckbothaction(ApplicationManager* pApp);
	void ReadActionParameters();
	void readycolors(GfxInfo dummy[],CFigure * figure[],int size ,int& rc, int & gc, int & yc, int & oc, int & blc, int & bc);
	void figs(int id, int game, color q, GfxInfo graphics[], CFigure* figure[], char identfier);
	void Execute();
};

//one for rectangle
//2 for square 
//3 for triangle
//4 for circle 
//5 is for hexagon



//one for red
//2 for orange 
//3 for black
//4 for green 
//5 for blue
//6 for yellow