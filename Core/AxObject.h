#pragma once

namespace Ax {

class AxObject
{
public:
	virtual void Begin() {};
	virtual void Update() {};
	virtual void End() {};
};

} // End Ax;