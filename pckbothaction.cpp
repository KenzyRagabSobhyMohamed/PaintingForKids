#include "pckbothaction.h"
#include "SelectOne.h"
#include "GUI/Output.h"
#include "GUI/Input.h"
#include "ApplicationManager.h"
#include <random>
#include <vector>
#include<string>  
#include "CHexagon.h"

pckbothaction::pckbothaction(ApplicationManager* pApp) :Action(pApp)
{
	r = 0, s = 0, c = 0, h = 0, t = 0;
	rrc = rblc = ryc = roc = rgc = rbc = src = sblc = syc = soc = sgc = sbc = crc = cblc = cyc = coc = cgc = cbc = trc = tblc = tyc = toc = tgc = tbc = hrc = hblc = hyc = hoc = hgc = hbc = 0;
	for (int i = 0; i < 200;i++)
	{
		arr[i] = NULL;
		rect[i] = NULL;
		cir[i] = NULL;
		sqa[i] = NULL;
		hex[i] = NULL;
		tri[i] = NULL;
	}
}

void pckbothaction::ReadActionParameters()
{

	int k = 0;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pManager->getfigdata(arr);//use load function instead of getfigdata
	while (arr[k] != NULL)
	{
		k++;
	}
	for (int i = 0; i < k; i++)
	{
		if (arr[i]->gettype() == 'r')
		{
			rect[r] = arr[i];
			r++;
		}
		if (arr[i]->gettype() == 't')
		{
			tri[t] = arr[i];
			t++;
		}
		if (arr[i]->gettype() == 'h')
		{
			hex[h] = arr[i];
			h++;
		}
		if (arr[i]->gettype() == 's')
		{
			sqa[s] = arr[i];
			s++;
		}
		if (arr[i]->gettype() == 'c')
		{
			cir[c] = arr[i];
			c++;
		}
	}
	//get graphics info for all rectangles
	readycolors(graphicsr, rect, r, rrc, rgc, ryc, roc, rblc, rbc);
	//get graphics info for all squares
	readycolors(graphicss, sqa, s, src, sgc, syc, soc, sblc, sbc);
	//get graphics info for all triangles
	readycolors(graphicst, tri, t, trc, tgc, tyc, toc, tblc, tbc);
	//get graphics info for all circles
	readycolors(graphicsc, cir, c, crc, cgc, cyc, coc, cblc, cbc);
	//get graphics info for all 
	readycolors(graphicsh, hex, h, hrc, hgc, hyc, hoc, hblc, hbc);

}

void pckbothaction::readycolors(GfxInfo graph[],CFigure* figure[],int size, int &rc, int &gc, int &yc, int &oc, int &blc, int &bc)
{
	for (int i = 0;i < size;i++)
	{
		graph[i] = figure[i]->GetGfxInfo();
		if (graph[i].isFilled)
		{
			if (graph[i].FillClr == RED)
				rc++;
			if (graph[i].FillClr == ORANGE)
				oc++;
			if (graph[i].FillClr == BLACK)
				blc++;
			if (graph[i].FillClr == YELLOW)
				yc++;
			if (graph[i].FillClr == GREEN)
				gc++;
			if (graph[i].FillClr == BLUE)
				bc++;
		}
	}
}


void pckbothaction::figs(int id, int ide, color ident, GfxInfo graphics[], CFigure* figure[], char identifier)
{
	GfxInfo dum;
	dum.DrawClr = DODGERBLUE;
	dum.FillClr = DODGERBLUE;
	dum.isFilled = false;
	dum.BorderWdth = 0;
	CHexagon dummy(p12, dum);
	int count;
	string k;//used to transform integer to 
	string col;
	string shape;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int totaltries = 0;
	int correct = 0;

	if (ident == RED)
		col = "red";
	if (ident == ORANGE)
		col = "orange";
	if (ident == GREEN)
		col = "green";
	if (ident == YELLOW)
		col = "yellow";
	if (ident == BLUE)
		col = "blue";
	if (ident == BLACK)
		col = "black";
	if (identifier == 'r')
		shape = "rectangle";
	if (identifier == 's')
		shape = "square";
	if (identifier == 't')
		shape = "triangle";
	if (identifier == 'h')
		shape = "hexagon";
	if (identifier == 'c')
		shape = "circle";

	pOut->PrintMessage("pick " + col + " " + shape);
	int w = ide;
	while (true)
	{
		if (w > 0)
		{
			pIn->GetPointClicked(p11.x, p11.y);
			totaltries++;
			for (int i = 0;i < id;i++)
			{
				if (figure[i]->IsInside(p11.x, p11.y) && graphics[i].isFilled && graphics[i].FillClr == ident)
				{
					k = to_string(w - 1);
					w--;
					pOut->PrintMessage("congrats you picked the right figure, only " + k + " remain");
					pManager->Deletefigure(figure[i]);
					pManager->UpdateInterface();
					pIn->GetPointClicked(p12.x, p12.y);//wait a sec
					correct++;
					figure[i] = &dummy;
					break;
				}
				else
				{
					pOut->PrintMessage("wrong figure");
				}
			}
		}
		if (w == 0)
		{
			string op = to_string(correct);
			string op2 = to_string(totaltries);
			pOut->PrintMessage("END OF GAME YOU SCORED ," + op + "/" + op2 + "CLICK");
			pIn->GetPointClicked(p12.x, p12.y);//wait for a sec
			return;
		}
	}

}


void pckbothaction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int C;
	string k;
	ReadActionParameters();

	const std::vector<int> intList{1, 2, 3, 4, 5, 6};
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, intList.size() - 1);
	int result = intList[distr(eng)];
	
	if (r == 0 && c == 0 && h == 0 && s == 0 && t == 0)
	{
		pOut->PrintMessage("please draw something before playing");
		return;

	}

	while ((result == 1 && r == 0) || (result == 2 && s == 0 ) || (result == 3 && t == 0) || (result == 4 && c == 0 ) || (result == 5 && h == 0 ) || (result == 6))
	{
		result = intList[distr(eng)];
	}


	int result2 = intList[distr(eng)];

	if (rrc==0 && rblc ==0 && ryc ==0 && roc ==0 && rgc ==0 && rbc ==0 && src ==0 && sblc ==0 && syc ==0 && soc ==0 && sgc ==0 && sbc ==0 && crc ==0 && cblc ==0 && cyc ==0 && coc ==0 && cgc ==0 && cbc ==0 && trc ==0 && tblc ==0 && tyc ==0 && toc ==0 && tgc ==0 && tbc ==0 && hrc ==0 && hblc ==0 && hyc ==0 && hoc ==0 && hgc ==0 && hbc == 0)
	{
		pOut->PrintMessage("please draw something with filled in color before playing");
		return;

	}


	if (result == 1)
	{
		while (true)
		{
			
			while ((result2==1 && rrc==0) || (result2 == 2 && roc == 0) || (result2 == 3 && rblc == 0) || (result2 == 4 && rgc == 0) || (result2 == 5 && rbc == 0) || (result2 == 6 && ryc == 0))
			{
				result2 = intList[distr(eng)];
			}
			if (result2 == 1)
			{
				figs(r, rrc, RED, graphicsr, rect, 'r');
				break;
			}
			if (result2 == 2)
			{
				figs(r, roc, ORANGE, graphicsr, rect, 'r');
				break;
			}
			if (result2 == 3)
			{
				figs(r, rblc, BLACK, graphicsr, rect, 'r');
				break;
			}
			if (result2 == 4)
			{
				figs(r, rgc, GREEN, graphicsr, rect, 'r');
				break;
			}
			if (result2 == 5)
			{
				figs(r, rbc, BLUE, graphicsr, rect, 'r');
				break;
			}
			if (result2 == 6)
			{
				figs(r, ryc, YELLOW, graphicsr, rect, 'r');
				break;
			}
		}
		return;
	}



	if (result == 2)
	{
		while (true)
		{
			while ((result2 == 1 && src == 0) || (result2 == 2 && soc == 0) || (result2 == 3 && sblc == 0) || (result2 == 4 && sgc == 0) || (result2 == 5 && sbc == 0) || (result2 == 6 && syc == 0))
			{
				result2 = intList[distr(eng)];
			}

			if (result2 == 1)
			{
				figs(s, src, RED, graphicss, sqa, 's');
				break;
			}
			if (result2 == 2)
			{
				figs(s, soc, ORANGE, graphicss, sqa, 's');
				break;
			}
			if (result2 == 3)
			{
				figs(s, sblc, BLACK, graphicss, sqa, 's');
				break;
			}
			if (result2 == 4)
			{
				figs(s, sgc, GREEN, graphicss, sqa, 's');
				break;
			}
			if (result2 == 5)
			{
				figs(s, sbc, BLUE, graphicss, sqa, 's');
				break;
			}
			if (result2 == 6)
			{
				figs(s, syc, YELLOW, graphicss, sqa, 's');
				break;
			}
		}
		return;
	}

	if (result == 3)
	{
		while (true)
		{
			while ((result2 == 1 && trc == 0) || (result2 == 2 && toc == 0) || (result2 == 3 && tblc == 0) || (result2 == 4 && tgc == 0) || (result2 == 5 && tbc == 0) || (result2 == 6 && tyc == 0))
			{
				result2 = intList[distr(eng)];
			}

			if (result2 == 1)
			{
				figs(t, trc, RED, graphicst, tri, 't');
				break;
			}
			if (result2 == 2)
			{
				figs(t, toc, ORANGE, graphicst, tri, 't');
				break;
			}
			if (result2 == 3)
			{
				figs(t, tblc, BLACK, graphicst, tri, 't');
				break;
			}
			if (result2 == 4)
			{
				figs(t, tgc, GREEN, graphicst, tri, 't');
				break;
			}
			if (result2 == 5)
			{
				figs(t, tbc, BLUE, graphicst, tri, 't');
				break;
			}
			if (result2 == 6)
			{
				figs(t, tyc, YELLOW, graphicst, tri, 't');
				break;
			}
		}
		return;
	}

	if (result == 4)
	{
		while (true)
		{
			while ((result2 == 1 && crc == 0) || (result2 == 2 && coc == 0) || (result2 == 3 && cblc == 0) || (result2 == 4 && cgc == 0) || (result2 == 5 && cbc == 0) || (result2 == 6 && cyc == 0))
			{
				result2 = intList[distr(eng)];
			}

			if (result2 == 1)
			{
				figs(c, crc, RED, graphicsc, cir, 'c');
				break;
			}
			if (result2 == 2)
			{
				figs(c, coc, ORANGE, graphicsc, cir, 'c');
				break;
			}
			if (result2 == 3)
			{
				figs(c, cblc, BLACK, graphicsc, cir, 'c');
				break;
			}
			if (result2 == 4)
			{
				figs(c, cgc, GREEN, graphicsc, cir, 'c');
				break;
			}
			if (result2 == 5)
			{
				figs(c, cbc, BLUE, graphicsc, cir, 'c');
				break;
			}
			if (result2 == 6)
			{
				figs(c, cyc, YELLOW, graphicsc, cir, 'c');
				break;
			}
		}
		return;
	}

	if (result == 5)
	{
		while (true)
		{
			while ((result2 == 1 && hrc == 0) || (result2 == 2 && hoc == 0) || (result2 == 3 && hblc == 0) || (result2 == 4 && hgc == 0) || (result2 == 5 && hbc == 0) || (result2 == 6 && hyc == 0))
			{
				result2 = intList[distr(eng)];
			}
			if (result2 == 1)
			{
				figs(c, hrc, RED, graphicsh, hex, 'h');
				break;
			}
			if (result2 == 2)
			{
				figs(c, hoc, ORANGE, graphicsh, hex, 'h');
				break;
			}
			if (result2 == 3)
			{
				figs(c, hblc, BLACK, graphicsh, hex, 'h');
				break;
			}
			if (result2 == 4)
			{
				figs(c, hgc, GREEN, graphicsh, hex, 'h');
				break;
			}
			if (result2 == 5)
			{
				figs(c, hbc, BLUE, graphicsh, hex, 'h');
				break;
			}
			if (result2 == 6)
			{
				figs(c, hyc, YELLOW, graphicsh, hex, 'h');
				break;
			}
		}
		return;
	}
}
