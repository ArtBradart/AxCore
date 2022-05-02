#include "AxNode.h"

namespace Ax {
	
AxNode::AxNode()
	: _parent(nullptr)
	, _location()
	, _prevLocation()
	, _isInited(false)
{}

AxNode::~AxNode()
{
	ClearVisual();
	_parent = nullptr;
	_childs.clear();
}

void AxNode::Init()
{
	_isInited = true;
	for (AxNode* child : _childs)
	{
		child->Init();
	}
	Redraw();
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

	if (IsInited()) Redraw();
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
	node->SetParent(this);

	if (IsInited()) Redraw();
}

void AxNode::RemoveChild(AxNode* node)
{
	const auto& res = find(_childs.begin(), _childs.end(), node);
	if (res != _childs.end()) return;

	_childs.erase(res);
	node->SetParent(nullptr);

	if (IsInited()) Redraw();
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

int AxNode::GetChildIndex(AxNode* child) const
{
	for (int i = 0; i < _childs.size(); i++)
	{
		if (child == _childs[i])
		{
			return i;
		}
	}
	return -1;
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
		_location = coord;
		this->OnLocationChanged();
	}
}

void AxNode::SetGlobalLocation(const AxCoord& coord)
{
	AxCoord loc = coord;
	if (_parent)
	{
		loc -= _parent->GetGlobalLocation();
	}
	SetLocation(loc);
}

void AxNode::Redraw()
{
	_prevLocation = GetGlobalLocation();
	for (AxNode* child : _childs) {
		child->Redraw();
	}
}

void AxNode::OnLocationChanged()
{
	if (IsInited()) Redraw();
}

} // End Ax.