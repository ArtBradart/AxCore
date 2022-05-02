#include "AxMenu.h"

#include "AxLog.h"
#include <conio.h>

namespace Ax {

AxMenu::AxMenu()
	: _currentItem(nullptr)
	, _targetItem(nullptr)
	, _colorSelect(StdColors::Select)
	, _countItems(10)
{
	_container = new AxListContainer();
	_container->SetParent(this);
	_container->SetLocation({ 3, 1 });

	_indicator = new AxLabel();
	_indicator->SetLocation({ 1, 1 });
	_indicator->SetParent(this);
	_indicator->SetText("> ");
	_indicator->SetColor((WORD)_colorSelect);

	_border = new AxBorder();
	_border->SetParent(this);
	_border->SetColor((WORD)StdColors::Select);
	_border->SetSize({ 16, 5 });
}

void AxMenu::Update()
{
	if (!_container || !_indicator) return;
	if (_container->GetChildsCount() == 0) return;
	if (!_targetItem)
		_targetItem = _container->GetChild(0)->As<AxMenuItem>();

	AxLog* log = AxLog::Instance();
	bool isDone = false;
	while (!isDone)
	{
		if (_currentItem == _targetItem)
		{
			// Input.
			switch (_getch())
			{
			case 72: //VK_UP
				{
					int selectedIdx = _container->GetChildIndex(_currentItem);
					if (selectedIdx > 0) _targetItem = _container->GetChild(selectedIdx - 1)->As<AxMenuItem>();
					break;
				}
			case 80: //VK_DOWN
				{
					int selectedIdx = _container->GetChildIndex(_currentItem);
					if (selectedIdx < _container->GetChildsCount() - 1) _targetItem = _container->GetChild(selectedIdx + 1)->As<AxMenuItem>();
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
		}

		// Update visual.
		if (_currentItem != _targetItem)
		{
			auto updateItem = [&](const string& text, WORD color) {
				AxCoord selectedPos = _currentItem->GetGlobalLocation();
				AxCoord indicatorPos = _container->GetLocation() + _currentItem->GetLocation() - AxCoord(2, 0);
				_indicator->SetLocation(indicatorPos);
				log->SetPosition(selectedPos.ToStdCoord());
				log->Output(text, color);
			};

			if (_currentItem)
				updateItem(_currentItem->Text(), _currentItem->Color());
			_currentItem = _targetItem;
			if (_currentItem)
				updateItem(_currentItem->Text(), (WORD)StdColors::Select);
		}
	}
}

void AxMenu::Add(AxNode* item)
{
	if (_container) _container->Add(item);
}

void AxMenu::Remove(AxNode* item)
{
	if (_container) _container->Add(item);
}

}