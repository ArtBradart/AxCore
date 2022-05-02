#pragma once

#include "AxNode.h"
#include "AxMenuItem.h"
#include "AxListContainer.h"

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
	void Add(AxNode* item);
	void Remove(AxNode* item);

protected:
	AxListContainer* _container;
	AxLabel* _indicator;
	AxMenuItem* _currentItem;
	AxMenuItem* _targetItem;

	StdColors _colorSelect;
	int _countItems;

};

}