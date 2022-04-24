#include "AxNode.h"

namespace Ax {
	
AxNode::AxNode(AxNode* parent, const AxCoord& location, const AxCoord& bounds)
	: _parent(parent)
	, _location(location)
	, _bounds(bounds)
{}

AxNode::~AxNode()
{
	_parent = nullptr;
	_childs.clear();
}

void AxNode::SetParent(AxNode* node)
{
	if (_parent == node) return;

	if (_parent)
	{
		_parent->RemoveChild(this);
	}

	_parent = node;

	if (_parent)
	{
		_parent->AddChild(this);
	}

}

AxNode* AxNode::GetParent() const
{
	return _parent;
}

void AxNode::AddChild(AxNode* node)
{
	const auto& res = find(_childs.begin(), _childs.end(), node);
	if (res != _childs.end()) return;

	_childs.push_back(node);
}

void AxNode::RemoveChild(AxNode* node)
{
	const auto& res = find(_childs.begin(), _childs.end(), node);
	if (res != _childs.end()) return;

	_childs.erase(res);
}

int AxNode::GetChildsCount() const
{
	return _childs.size();
}

const vector<AxNode*>& AxNode::GetChilds() const
{
	return _childs;
}

AxNode* AxNode::GetChild(int index)
{
	return _childs[index];
}

AxCoord AxNode::GetLocation() const
{
	return _location;
}

AxCoord AxNode::GetGlobalLocation() const
{
	AxCoord loc = _location;
	if (_parent)
	{
		loc += _parent->GetGlobalLocation();
	}
	return loc;
}

void AxNode::SetLocation(const AxCoord& coord)
{
	if (_location != coord)
	{
		AxCoord prevValue = _location;
		_location = coord;
		this->OnLocationChanged(prevValue);
	}
}

AxCoord AxNode::GetBounds() const
{
	return _bounds;
}

void AxNode::SetBounds(const AxCoord& coord)
{
	if (_bounds != coord)
	{
		AxCoord prevValue = _bounds;
		_bounds = coord;
		this->OnBoundsChanged(prevValue);
	}
}

void AxNode::OnLocationChanged(const AxCoord& prewCoord)
{}

void AxNode::OnBoundsChanged(const AxCoord& prewCoord)
{}

} // End Ax.