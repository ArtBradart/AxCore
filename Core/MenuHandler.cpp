#include "MenuHandler.h"
#include "Log.h"

MenuHandler::MenuHandler(Menu& menu)
	: _menu(menu)
{
	_selected = _menu._list.begin();
	_target = _menu._list.begin();
	if(!_menu._list.empty()) BeginPlay();
}

void MenuHandler::BeginPlay()
{
	/// First output
	
	TitleStart = Log::GetPosition();
	Log::Output(_menu._title.Text() + '\n', _menu._title.Color());
	TitleEnd = Log::GetPosition();

	ListStart = Log::GetPosition();
	for (const MenuItem& item : _menu._list)
	{
		Log::Output("  " + item.Text() + '\n', item.Color());
	}
	ListEnd = Log::GetPosition();

	int _selectedPos = distance(_menu._list.begin(), _selected);
	Log::SetPosition({ ListStart.X, ListStart.Y + short(_selectedPos) });
	Log::Output("> " + _selected->Text(), StdColors::Select);
	//Log::SetPosition(ListEnd);


	while (Tick());

	EndPlay();
}

bool MenuHandler::Tick()
{
	if (_menu._list.begin() == _menu._list.end()) return false;
	if (_selected != _target)
	{
		int _selectedPos = distance(_menu._list.begin(), _selected);
		Log::SetPosition({ ListStart.X, ListStart.Y + short(_selectedPos) });
		Log::Output("  " + _selected->Text(), _selected->Color());
		int _targetPos = distance(_menu._list.begin(), _target);
		Log::SetPosition({ ListStart.X, ListStart.Y + short(_targetPos) });
		Log::Output("> " + _target->Text(), StdColors::Select);
		_selected = _target;
		//Log::SetPosition(ListEnd);
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

void MenuHandler::EndPlay()
{
	auto clearstring = [](const string& str) {
		for (const char& c : str)
		{
			cout << ' ';
		}
	};

	Log::SetPosition(TitleStart);
	clearstring(_menu._title.Text());

	Log::SetPosition(ListStart);
	for (const MenuItem& item : _menu._list)
	{
		clearstring("  " + item.Text());
		cout << endl;
	}
	Log::SetPosition(TitleStart);
}
