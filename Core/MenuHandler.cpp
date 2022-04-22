#include "MenuHandler.h"
#include "Log.h"

MenuHandler::MenuHandler(Menu& menu)
	: _menu(menu)
{
	_selected = _menu._list.begin();
	_target = _menu._list.begin();
	if(!_menu._list.empty()) Begin();
}

void MenuHandler::Begin()
{
	/// First output

	TitleStart = Log::Instance()->GetPosition();
	Log::Instance()->Output(_menu._title.Text() + '\n', _menu._title.Color());
	TitleEnd = Log::Instance()->GetPosition();

	ListStart = Log::Instance()->GetPosition();
	for (const MenuItem& item : _menu._list)
	{
		Log::Instance()->Output("  " + item.Text() + '\n', item.Color());
	}
	ListEnd = Log::Instance()->GetPosition();

	int _selectedPos = distance(_menu._list.begin(), _selected);
	Log::Instance()->SetPosition({ ListStart.X, ListStart.Y + short(_selectedPos) });
	Log::Instance()->Output("> " + _selected->Text(), StdColors::Select);
	//Log::Instance()->SetPosition(ListEnd);

	while (Tick());

	End();
}

bool MenuHandler::Tick()
{
	if (_menu._list.begin() == _menu._list.end()) return false;

	if (_selected != _target)
	{
		int _selectedPos = distance(_menu._list.begin(), _selected);
		Log::Instance()->SetPosition({ ListStart.X, ListStart.Y + short(_selectedPos) });
		Log::Instance()->Output("  " + _selected->Text(), _selected->Color());
		int _targetPos = distance(_menu._list.begin(), _target);
		Log::Instance()->SetPosition({ ListStart.X, ListStart.Y + short(_targetPos) });
		Log::Instance()->Output("> " + _target->Text(), StdColors::Select);
		_selected = _target;
		Log::Instance()->SetPosition(ListEnd);
	}

	switch (_getch())
	{
	case 72: //VK_UP
		_target = (_selected == _menu._list.begin() ? _menu._list.end() : _selected) - 1;
		break;
	case 80: //VK_DOWN
		_target = _selected == _menu._list.end() - 1 ? _menu._list.begin() : _selected + 1;
		break;
	case VK_ESCAPE: return false;
	case VK_RETURN:
		_selected->Action();
		return false;
	}

	return true;
}

void MenuHandler::End()
{
	auto clearstring = [](const string& str) {
		for (const char& c : str)
		{
			cout << ' ';
		}
	};

	Log::Instance()->SetPosition(TitleStart);
	clearstring(_menu._title.Text());

	Log::Instance()->SetPosition(ListStart);
	for (const MenuItem& item : _menu._list)
	{
		clearstring("  " + item.Text());
		cout << endl;
	}
	Log::Instance()->SetPosition(TitleStart);
}
