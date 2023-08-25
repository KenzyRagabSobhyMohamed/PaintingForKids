#ifndef CFIGURE_H
#define CFIGURE_H
#include<fstream>
#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	char type;
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	double CalcDistance(Point, Point) const; //utility function to measure the length between two points
	/// Add more parameters if needed.

public:
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	GfxInfo GetGfxInfo()const;
	void SetID(int id);				//Sets ID to figure's index in FigList.
	int GetID() const;				//Gets the ID of the figure
	char gettype();
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	virtual bool IsInside(int ,int ) const= 0;
	virtual void PrintInfo(Output* pOut) const = 0;	//print all figure information
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
    virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual string GetColorname(color c);
	virtual color GetColor(string s);
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	void SaveByID(ofstream& Outfile, int id);
};

#endif