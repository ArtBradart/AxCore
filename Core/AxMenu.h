#pragma once

#include "AxObject.h"
#include "AxLabel.h"
#include "AxMenuItem.h"
#include "AxMenuList.h"

namespace Ax {

class AxMenu : public AxObject
{
public:
	AxMenu();
	AxMenu(const string& text);
	AxMenu(const AxLabel& title);

	AxLabel _title;
	AxMenuList _list;
};

}