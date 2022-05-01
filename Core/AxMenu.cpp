#include "AxMenu.h"

#include "AxLog.h"
#include <conio.h>

namespace Ax {

AxMenu::AxMenu()
	: _currentItem(nullptr)
	, _colorSelect(StdColors::Select)
	, _countItems(10)
{}

void AxMenu::Update()
{
	if (GetChildsCount() == 0) return;

	AxLog* log = AxLog::Instance();
	bool isDone = false;
	while (!isDone)
	{
		// Input.
		switch (_getch())
		{
		case 72: //VK_UP
			{
				int selectedIdx = GetChildIndex(_currentItem);
				if (selectedIdx > 0) _targetItem = GetChild(selectedIdx - 1)->As<AxMenuItem>();
				break;
			}
		case 80: //VK_DOWN
			{
				int selectedIdx = GetChildIndex(_currentItem);
				if (selectedIdx < GetChildsCount() - 1) _targetItem = GetChild(selectedIdx + 1)->As<AxMenuItem>();
				break;
			}
		case VK_ESCAPE: 
			isDone = true;
			break;
		case VK_RETURN:
			if (_currentItem) _currentItem->Action();
			isDone = true;
			break;
		}

		// Update visual.
		if (_currentItem != _targetItem)
		{
			auto updateItem = [&](const string& text, WORD color) {
				int selectedIdx = GetChildIndex(_currentItem);
				AxCoord selectedPos = GetGlobalLocation() + AxCoord(0, selectedIdx);
				log->SetPosition(selectedPos.ToStdCoord());
				log->Output(text, color);
			};

			if (_currentItem)
				updateItem("  " + _currentItem->Text(), _currentItem->Color());
			_currentItem = _targetItem;
			if (_currentItem)
				updateItem("> " + _targetItem->Text(), (WORD)StdColors::Select);
		}
	}
}

}