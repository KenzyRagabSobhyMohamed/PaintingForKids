#include "Actions/Action.h"
#include "Figures/CFigure.h"

class SelectOne : public Action
{
private:
	Point P;  //Clicked point
	CFigure* SelectedFigure; //Clicked figure (NULL if no figure is clicked)
public:
	SelectOne(ApplicationManager* pApp);

	//Reads select parameters
	virtual void ReadActionParameters();

	//Executes the select action
	virtual void Execute();
	void Select();
	void Unselect();
};
