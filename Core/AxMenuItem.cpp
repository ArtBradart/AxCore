#include "AxMenuItem.h"

namespace Ax {

AxMenuItem::AxMenuItem()
	: _action(nullptr)
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