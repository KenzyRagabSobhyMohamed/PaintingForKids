#include "pckshapeaction.h"
#include "SelectOne.h"
#include "GUI/Output.h"
#include "GUI/Input.h"
#include "ApplicationManager.h"
#include <random>
#include <vector>
#include<string>  
#include "CHexagon.h"
pckshapeaction::pckshapeaction(ApplicationManager * pApp) :Action(pApp)
{
	s = 0;
	r = 0;
	c = 0;
	h = 0;
	t = 0;
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



void pckshapeaction::ReadActionParameters()
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
}



void pckshapeaction::picks(CFigure* figure[], char id, int size)
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
	string shape;
	string k;
	int correct = 0;
	int totaltries = 0;

	if (id == 'r')
	{
		shape = "rectangle";
	}
	if (id == 'c')
	{
		shape = "circle";
	}
	if (id == 's')
	{
		shape = "square";
	}
	if (id == 'h')
	{
		shape = "hexagon";
	}
	if (id == 't')
	{
		shape = "triangle";
	}


	pOut->PrintMessage("pick " + shape);
	C = 0;
	while (true)
	{
		if (C < size)
		{
			pIn->GetPointClicked(p1.x, p1.y);
			totaltries++;
			for (int i = 0;i < size;i++)
			{
				if (figure[i]->IsInside(p1.x, p1.y))
				{
					k = to_string((size - C - 1));
					C++;
					pOut->PrintMessage("Congrats you picked a " + shape + ", remaining" + shape + " = " + k);
					pManager->Deletefigure(figure[i]);
					pManager->UpdateInterface();
					pIn->GetPointClicked(p2.x, p2.y); //wait for a sec
					correct++;
					figure[i] = &dummy;
					break;

				}
				else
				{
					pOut->PrintMessage("NOT THE CORRECT FIGURE");
				}
			}
		}
		if (C == size)
		{
			string op = to_string(correct);
			string op2 = to_string(totaltries);
			pOut->PrintMessage("END OF GAME YOU SCORED " + op + "/" + op2 + " ,CLICK");
			pIn->GetPointClicked(p2.x, p2.y);//wait for a sec
			return;
		}
	}


}









void pckshapeaction::Execute()
{

	ReadActionParameters();
	//one for rectangle
	//2 for square 
	//3 for triangle
	//4 for circle 
	//5 is for hexagon
	Output* pOut = pManager->GetOutput();

	const std::vector<int> intList{ 1, 2, 3, 4,5 };
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, intList.size() - 1);
	int result = intList[distr(eng)];

	if (r == 0 && c == 0 && h == 0 && s == 0 && t == 0)
	{
		pOut->PrintMessage("please draw something before playing");
		return;

	}

	while ((result==1 && r==0) || (result == 2 && s == 0) || (result == 3 && t == 0) || (result == 4 && c == 0) || (result == 5 && h == 0))
	{
		result = intList[distr(eng)];
	}
	if (result == 1)
	{
		picks(rect, 'r', r);

		return;
	}

	if (result == 2)
	{
		picks(sqa, 's', s);
		return;
	}

	if (result == 4)
	{
		picks(cir, 'c', c);
		return;

	}

	if (result == 3)
	{
		picks(tri, 't', t);
		return;
	}

	if (result == 5)
	{
		picks(hex, 'h', h);
		return;
	}

}
