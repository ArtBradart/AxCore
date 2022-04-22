#pragma once

#include "Title.h"

class MenuItem : public Title
{
typedef Title Super ;
public:
	MenuItem();
	MenuItem(const function<void()>& action);
	MenuItem(const function<void()>& action, const string& text);
	MenuItem(const function<void()>& action, const string& text, WORD color);

	void SetAction(const function<void()>& action);
	void Action();

protected:
	function<void()> _action;
};