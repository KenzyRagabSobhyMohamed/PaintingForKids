#include "GUI/UI_Info.h"
#include "GUI/Output.h"
#include "GUI/Input.h"
#include "Actions/Action.h"



class switchaction : public Action
{
public:

	switchaction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
	~switchaction();
};