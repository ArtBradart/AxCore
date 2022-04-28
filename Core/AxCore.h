#pragma once

#include "AxNode.h"

namespace Ax {

class AxCore
{
public:
	AxCore();
	~AxCore();

	void Begin();
	void Update();
	void End();

	void SetRootNode(AxNode* rootNode);
	AxNode* GetRootNode() const;

protected:
	void OnRootNodeChanged(AxNode* prevRoot);

protected:
	AxNode* _rootNode;

};

} // End Ax.