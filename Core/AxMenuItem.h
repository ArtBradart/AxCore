#pragma once

#include "AxLabel.h"

namespace Ax {

class AxMenuItem : public AxLabel
{
typedef AxLabel Super ;
public:
	AxMenuItem();
	AxMenuItem(const function<void()>& action);
	AxMenuItem(const function<void()>& action, const string& text);
	AxMenuItem(const function<void()>& action, const string& text, WORD color);

	void SetAction(const function<void()>& action);
	void Action();

protected:
	function<void()> _action;
};

} // End Ax.