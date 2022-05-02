#pragma once
#include "AxNode.h"

namespace Ax {

class AxListContainer : public AxNode
{
public:
	AxListContainer();

	void Add(AxNode* item);
	void Remove(AxNode* item);

};

} // End Ax.