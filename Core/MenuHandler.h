#pragma once

#include "Common.h"
#include "Menu.h"

static class StdColors
{
public:
	static const WORD Title = 0x00F0;
	static const WORD Item = 0x0007;
	static const WORD Select = 0x000F;
	static const WORD Back = 0x0007;
};

class MenuHandler
{
public:
	MenuHandler(Menu& menu);

protected:
	void BeginPlay();
	bool Tick();
	void EndPlay();
protected:
	Menu _menu;

	DWORD ColorSelect = StdColors::Select;

	vector<MenuItem>::iterator _selected;
	vector<MenuItem>::iterator _target;

	COORD TitleStart;
	COORD TitleEnd;
	COORD ListStart;
	COORD ListEnd;

};
