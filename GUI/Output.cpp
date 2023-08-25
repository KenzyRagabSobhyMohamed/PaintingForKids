#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250 * 2;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 55;
	UI.MenuItemWidth = 55;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\1-Rectangle.jpeg";
	MenuItemImages[ITM_SQU] = "images\\MenuItems\\2-Sqaure.jpeg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\3-Hexagon.jpeg";
	MenuItemImages[ITM_CIR] = "images\\MenuItems\\4-Circle.jpeg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\5-Triangle.jpeg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\6- Move.jpeg";
	MenuItemImages[ITM_SEL] = "images\\MenuItems\\7- Select.jpeg";
	MenuItemImages[ITM_PEN] = "images\\MenuItems\\8- Pencil.jpeg";
	MenuItemImages[ITM_FILL] = "images\\MenuItems\\9- Fill.jpeg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\10- Black.jpeg";
	MenuItemImages[ITM_YELL] = "images\\MenuItems\\11- Yellow.jpeg";
	MenuItemImages[ITM_ORAN] = "images\\MenuItems\\12- Orange.jpeg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\13- Red.jpeg";
	MenuItemImages[ITM_GREE] = "images\\MenuItems\\14- Green.jpeg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\15- Blue.jpeg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\16- Undo.jpeg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\17- Redo.jpeg";
	MenuItemImages[ITM_DEL] = "images\\MenuItems\\18- Delete.jpeg";
	MenuItemImages[ITM_CLEAR] = "images\\MenuItems\\19- Clear.jpeg";
	MenuItemImages[ITM_REC] = "images\\MenuItems\\20- Record.jpeg";
	MenuItemImages[ITM_STOP] = "images\\MenuItems\\21- Stop.jpeg";
	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\22- Play.jpeg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\23- Save.jpeg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\24- Load.jpeg";
	MenuItemImages[ITM_VOICE] = "images\\MenuItems\\Voice.jpg";
	MenuItemImages[ITM_SWIT] = "images\\MenuItems\\25- Switch.jpeg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\26- Exit.jpeg";

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	string ItemImages[PLAY_ITM_COUNT];
	ItemImages[ITM_HIDE_SEEK] = "images\\MenuItems\\Both.jpeg";
	ItemImages[ITM_FIND_SHAPE] = "images\\MenuItems\\Shape.jpeg";
	ItemImages[ITM_FIND_COLOR] = "images\\MenuItems\\Color.jpeg";
	ItemImages[ITM_SWITCH] = "images\\MenuItems\\25- Switch.jpeg";
	ItemImages[ITM_EXT] = "images\\MenuItems\\26- Exit.jpeg";

	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(ItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea2() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
void  Output::setIsfilled(bool x)    //check if the figure is filled or not
{
	UI.FillColor = x;

}
void Output::setCrntDrawColor(color p)
{
	UI.DrawColor = p;

}
/// //////////////////////////////////////////////////////////////////////////////////

void Output::setCrntFillColor(color o)
{
	UI.FillColor = o;
}
color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::DrawCircle(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected)
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int radius = sqrt((P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y));

	pWind->DrawCircle(P1.x, P1.y, radius, style);

}

void Output::DrawTria(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected) const

{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}

void Output::DrawSqu(Point P1, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawRectangle(P1.x - 60, P1.y - 60, P1.x + 60, P1.y + 60, style);

}

void Output::DrawHexagon(Point P1, GfxInfo HextGfxInfo, bool selected)
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HextGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HextGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HextGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int l = 150;
	int x = P1.x;
	int y = P1.y;
	int X[6] = { x, x + (sqrt(3) / 2) * l,x + (sqrt(3) / 2) * l ,x, x - (sqrt(3) / 2) * l,x - (sqrt(3) / 2) * l };
	int Y[6] = { y + l , y + l / 2,y - l / 2,y - l,y - l / 2,y + l / 2 };

	pWind->DrawPolygon(X, Y, 6, style);

}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

