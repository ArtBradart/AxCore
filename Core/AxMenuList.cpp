#include "AxMenuList.h"

namespace Ax {

void AxMenuList::Add(const AxMenuItem& item)
{
	push_back(item);
}

}