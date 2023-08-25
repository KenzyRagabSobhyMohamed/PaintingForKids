#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQU: return DRAW_SQU;
			case ITM_HEX: return DRAW_HEX;
			case ITM_CIR: return DRAW_CIR;
			case ITM_TRI: return DRAW_TRI;
			case ITM_MOVE: return DRAW_MOVE;
			case ITM_SEL: return DRAW_SEL;
			case ITM_PEN: return DRAW_PEN;
			case ITM_FILL: return DRAW_FILL;
			case ITM_BLACK: return DRAW_BLACK;
			case ITM_YELL: return DRAW_YELL;
			case ITM_ORAN: return DRAW_ORAN;
			case ITM_RED: return DRAW_RED;
			case ITM_GREE: return DRAW_GREE;
			case ITM_BLUE: return DRAW_BLUE;
			case ITM_UNDO: return DRAW_UNDO;
			case ITM_REDO: return DRAW_REDO;
			case ITM_DEL: return DRAW_DEL;
			case ITM_CLEAR: return DRAW_CLEAR;
			case ITM_REC: return DRAW_REC;
			case ITM_STOP: return DRAW_STOP;
			case ITM_PLAY: return DRAW_PLAY;
			case ITM_SAVE: return DRAW_SAVE;
			case ITM_LOAD: return DRAW_LOAD;
			case ITM_VOICE: return DRAW_VOICE;
			case ITM_SWIT: return TO_PLAY;
			case ITM_EXIT: return EXIT;

			default:return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		{
			//[1] If user clicks on the Toolbar
			if (y >= 0 && y < UI.ToolBarHeight)
			{
				int ClickedItemOrder = (x / UI.MenuItemWidth);
				//Divide x coord of the point clicked by the menu item width (int division)
				//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

				switch (ClickedItemOrder)
				{
				case ITM_HIDE_SEEK:return DRAW_HIDE_SEEK;
				case ITM_FIND_SHAPE: return DRAW_FIND_SHAPE;
				case ITM_FIND_COLOR:return DRAW_FIND_COLOR;
				case ITM_SWITCH: return TO_DRAW;
				case ITM_EXT: return EXIT;
				}
				//[2] User clicks on the drawing area
				if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
				{
					return DRAWING_AREA;
				}

				//[3] User clicks on the status bar
				return STATUS;
			}
		}
	}

}
/////////////////////////////////

Input::~Input()
{
}
