#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void ClearDrawArea2() const;
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;//Draw a rectangle
	void DrawCircle(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false);
	void DrawTria(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a triangle
	void DrawHexagon(Point P1, GfxInfo HextGfxInfo, bool selected = false);
	void DrawSqu(Point P1, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a square
	///Make similar functions for drawing all other figure types.

	void PrintMessage(string msg) const;	//Print a message on Status bar
	void setCrntDrawColor(color p);       // set the color of the dawing
	void   setCrntFillColor(color o);      // set the color of the filling
	void setIsfilled(bool);           //set the figure is filled
	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width


	~Output();
};

#endif