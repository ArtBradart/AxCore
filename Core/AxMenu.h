#pragma once

#include "AxNode.h"
#include "AxMenuItem.h"

namespace Ax {

enum class StdColors : WORD
{
	Title = 0x00F0,
	Item = 0x0007,
	Select = 0x000F,
	Back = 0x0007
};

class AxMenu : public AxNode
{
public:
	AxMenu();

	void Update();

protected:
	AxMenuItem* _currentItem;
	AxMenuItem* _targetItem;

	StdColors _colorSelect;
	int _countItems;

};

}