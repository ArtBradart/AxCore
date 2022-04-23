#pragma once

#include "Common.h"
#include "AxMenuItem.h"

namespace Ax {

class AxMenuList : public vector<AxMenuItem>
{
public:
	void Add(const AxMenuItem& item);

};

} // End Ax.