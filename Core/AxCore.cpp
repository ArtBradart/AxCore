#include "AxCore.h"

namespace Ax {

AxCore::AxCore()
{
	Begin();
	Update();
	End();
}

AxCore::~AxCore()
{}

void AxCore::Begin()
{

}

void AxCore::Update()
{
	bool isActive = true;
	while (isActive)
	{
		
	}
}

void AxCore::End()
{

}

void AxCore::SetRootNode(AxNode* rootNode)
{
	if (_rootNode != rootNode) {
		AxNode* prevRoot = _rootNode;
		_rootNode = rootNode;
		OnRootNodeChanged(prevRoot);
	}
}

AxNode* AxCore::GetRootNode() const
{
	return _rootNode;
}

void AxCore::OnRootNodeChanged(AxNode* prevRoot)
{}

} // End Ax.