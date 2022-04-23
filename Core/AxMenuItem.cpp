#include "AxMenuItem.h"

namespace Ax {

AxMenuItem::AxMenuItem()
	: _action(nullptr)
{}

AxMenuItem::AxMenuItem(const function<void()>& action)
	: _action(action)
{}

AxMenuItem::AxMenuItem(const function<void()>& action, const string & text)
	: Super(text)
	, _action(action)
{}

AxMenuItem::AxMenuItem(const function<void()>& action, const string & text, WORD color)
	: Super(text, color)
	, _action(action)
{}



void AxMenuItem::SetAction(const function<void()>& action)
{
	_action = action;
}

void AxMenuItem::Action()
{
	if (_action == nullptr) return;
	_action();
}

} // End Ax.