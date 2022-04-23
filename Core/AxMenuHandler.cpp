#include "AxMenuHandler.h"
#include "Log.h"

namespace Ax {

AxMenuHandler::AxMenuHandler(AxMenu& menu)
	: _menu(menu)
{
	_selected = _menu._list.begin();
	_target = _menu._list.begin();
	if(!_menu._list.empty()) Begin();
}

void AxMenuHandler::Begin()
{
	/// First output

	const auto& logInst = Log::Instance();
	TitleStart = logInst->GetPosition();
	logInst->Output(_menu._title.Text() + '\n', _menu._title.Color());
	TitleEnd = logInst->GetPosition();

	ListStart = logInst->GetPosition();
	for (const AxMenuItem& item : _menu._list)
	{
		logInst->Output("  " + item.Text() + '\n', item.Color());
	}
	ListEnd = Log::Instance()->GetPosition();

	int _selectedPos = distance(_menu._list.begin(), _selected);
	logInst->SetPosition({ ListStart.X, ListStart.Y + short(_selectedPos) });
	logInst->Output("> " + _selected->Text(), StdColors::Select);
	//logInst->SetPosition(ListEnd);

	while (Tick());

	End();
}

bool AxMenuHandler::Tick()
{
	const auto& logInst = Log::Instance();

	if (_menu._list.begin() == _menu._list.end()) return false;

	if (_selected != _target)
	{
		int _selectedPos = distance(_menu._list.begin(), _selected);
		logInst->SetPosition({ ListStart.X, ListStart.Y + short(_selectedPos) });
		logInst->Output("  " + _selected->Text(), _selected->Color());
		int _targetPos = distance(_menu._list.begin(), _target);
		logInst->SetPosition({ ListStart.X, ListStart.Y + short(_targetPos) });
		logInst->Output("> " + _target->Text(), StdColors::Select);
		_selected = _target;
		logInst->SetPosition(ListEnd);
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

void AxMenuHandler::End()
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
	for (const AxMenuItem& item : _menu._list)
	{
		clearstring("  " + item.Text());
		cout << endl;
	}
	Log::Instance()->SetPosition(TitleStart);
}

}