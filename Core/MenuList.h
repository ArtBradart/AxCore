#pragma once

#include "Common.h"
#include "MenuItem.h"

class MenuList : public vector<MenuItem>
{
public:
	void Add(const MenuItem& item);

};