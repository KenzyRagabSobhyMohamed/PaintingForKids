#include "pckcoloraction.h"
#include "SelectOne.h"
#include "GUI/Output.h"
#include "GUI/Input.h"
#include "ApplicationManager.h"
#include <random>
#include <vector>
#include<string>  
#include "CHexagon.h"
pckcoloraction::pckcoloraction(ApplicationManager* pApp) :Action(pApp)
{
	p1.x = 0;
	p1.y = 0;
	p2.x = 0;
	p2.y = 0;
	rc = yc = blc = bc = oc = gc = q = 0;
}

void pckcoloraction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pManager->getfigdata(list);//use load function instead of getfigdata
	while (list[q] != NULL)
	{
		q++;
	}
	for (int i = 0;i < q;i++)
	{
		graphics[i] = list[i]->GetGfxInfo();
		if (graphics[i].isFilled)
		{
			if (graphics[i].FillClr == RED)
			{
				rc++;
			}

			if (graphics[i].FillClr == GREEN)
			{
				gc++;
			}

			if (graphics[i].FillClr == YELLOW)
			{
				yc++;
			}

			if (graphics[i].FillClr == BLACK)
			{
				blc++;
			}

			if (graphics[i].FillClr == BLUE)
			{
				bc++;
			}

			if (graphics[i].FillClr == ORANGE)
			{
				oc++;
			}

		}
	}

}


void pckcoloraction::picks(color colors, int size)
{

	GfxInfo dum;
	dum.DrawClr = DODGERBLUE;
	dum.FillClr = DODGERBLUE;
	dum.isFilled = false;
	dum.BorderWdth = 0;
	CHexagon dummy(p2, dum);
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int C;
	string k;
	string coloring;

	if (colors == RED)
	{
		coloring = "red";
	}

	if (colors == GREEN)
	{
		coloring = "green";
	}
	if (colors == BLACK)
	{
		coloring = "black";
	}
	if (colors == YELLOW)
	{
		coloring = "yellow";
	}
	if (colors == ORANGE)
	{
		coloring = "orange";
	}
	if (colors == BLUE)
	{
		coloring = "blue";
	}


	int c = size;
	int correct = 0;
	int totaltries = 0;
	pOut->PrintMessage("pick " + coloring + " colors");
	while (true)
	{

		if (c > 0)
		{
			pIn->GetPointClicked(p1.x, p1.y);
			totaltries++;
			for (int i = 0;i < q;i++)
			{
				if (list[i]->IsInside(p1.x, p1.y) && graphics[i].isFilled && graphics[i].FillClr == colors)
				{
					k = to_string((c - 1));
					pOut->PrintMessage("congrats, you picked a " + coloring + " colored shape remaining shapes = " + k);
					pManager->Deletefigure(list[i]);
					pManager->UpdateInterface();
					pIn->GetPointClicked(p2.x, p2.y);
					c--;
					correct++;
					list[i] = &dummy;
					break;
				}
				else
				{
					pOut->PrintMessage("Not a correct figure");
				}
			}
			if (c == 0)
			{
				string op = to_string(correct);
				string op2 = to_string(totaltries);
				pOut->PrintMessage("END OF GAME YOU SCORED ," + op + "/" + op2 + "CLICK");
				pIn->GetPointClicked(p2.x, p2.y);//wait for a sec

				break;
			}
		}
	}



}


void pckcoloraction::Execute()
{
	ReadActionParameters();
	//one for red
	//2 for orange 
	//3 for black
	//4 for green 
	//5 for blue
	//6 for yellow
	const std::vector<int> intList{ 1,2,3,4,5,6 };
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, intList.size() - 1);
	int result = intList[distr(eng)];
	//check for red colors 
	Output* pOut = pManager->GetOutput();

	if (rc==0 && oc==0 && bc==0 && blc==0 && gc==0 && yc==0)
	{
		pOut->PrintMessage("please draw something with filled in color before playing");
		return;

	}

	while ((result == 1 && rc == 0) || (result == 2 && oc == 0) || (result == 3 && blc == 0) || (result == 4 && gc == 0) || (result == 5 && bc == 0)|| (result==6 && yc==0))
	{
		result = intList[distr(eng)];
	}



	if (result == 1)
	{
		picks(RED, rc);
		return;
	}
	//check for oranges 
	if (result == 2)
	{
		picks(ORANGE, oc);
		return;
	}
	//checks for black 
	if (result == 3)
	{
		picks(BLACK, blc);
		return;
	}
	//checks for green
	if (result == 4)
	{
		picks(GREEN, gc);
		return;
	}
	//check for blue
	if (result == 5)
	{
		picks(BLUE, bc);
		return;
	}
	//check for yellow
	if (result == 6)
	{
		picks(YELLOW, yc);
		return;
	}

}