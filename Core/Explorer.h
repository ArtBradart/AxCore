#pragma once

#include "Common.h"
#include "Menu.h"

class Explorer
{
public:
	Explorer();
	~Explorer();

	bool ConstructList(Menu& list);
	bool GetDevices(Menu& list);
	bool GetDirectories(Menu& list);

protected:
	void BeginPlay();
	bool Tick();

private:
	HANDLE _hConsole;

	vector<string> _path;

	bool _Running;
};