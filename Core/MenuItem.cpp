#include "MenuItem.h"

MenuItem::MenuItem()
	: _action(nullptr)
{}

MenuItem::MenuItem(const function<void()>& action)
	: _action(action)
{}

MenuItem::MenuItem(const function<void()>& action, const string & text)
	: Super(text)
	, _action(action)
{}

MenuItem::MenuItem(const function<void()>& action, const string & text, WORD color)
	: Super(text, color)
	, _action(action)
{}



void MenuItem::SetAction(const function<void()>& action)
{
	_action = action;
}

void MenuItem::Action()
{
	if (_action == nullptr) return;
	_action();
}
