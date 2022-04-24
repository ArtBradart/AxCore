#pragma once

#include "AxNode.h"

namespace Ax {

class AxMenu : public AxNode
{
public:
	AxMenu();



protected:
	AxNode* _currentItem;

};

}