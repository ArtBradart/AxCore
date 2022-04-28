#pragma once

#include <functional>

#include "AxLabel.h"

namespace Ax {

class AxMenuItem : public AxLabel
{
typedef AxLabel Super;
public:
	AxMenuItem();

	void SetAction(const function<void()>& action);
	void Action();

protected:
	function<void()> _action;
};

} // End Ax.