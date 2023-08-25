#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,//Draw Rectangle
	DRAW_SQU,//Draw Square
	DRAW_HEX,//Draw Hexagon
	DRAW_CIR,//Draw Circle
	DRAW_TRI,//Draw Triangle
	DRAW_MOVE,//Draw Move
	DRAW_SEL,//Draw Select
	DRAW_PEN,//Draw Pencil
	DRAW_FILL,//Draw Fill
	DRAW_BLACK,//Draw Black
	DRAW_YELL,//Draw Yellow
	DRAW_ORAN,//Draw Orange
	DRAW_RED,//Draw Red
	DRAW_GREE,//Draw Green
	DRAW_BLUE,//Draw  Blue
	DRAW_UNDO,//Draw Undo
	DRAW_REDO,//Draw Redo
	DRAW_DEL,//Draw Delete
	DRAW_CLEAR,//Draw Clear
	DRAW_REC,//Draw Record
	DRAW_STOP,//Draw  Stop
	DRAW_PLAY,//Draw Play
	DRAW_SAVE,//Draw Save
	DRAW_LOAD,//Draw Load
	DRAW_VOICE,
	DRAW_HIDE_SEEK,
	DRAW_FIND_COLOR,
	DRAW_FIND_SHAPE,
	EXIT,			//Exit
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS			//A click on the status bar

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif