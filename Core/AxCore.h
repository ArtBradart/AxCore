#pragma once

#include "AxObject.h"

namespace Ax {

class AxCore
{
public:
	AxCore();
	~AxCore();

	void Begin();
	void Update();
	void End();
	
};

} // End Ax.