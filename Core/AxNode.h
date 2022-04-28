#pragma once

#include <vector>
#include "AxCoord.h"

namespace Ax {

using namespace std;

class AxNode
{
public:
	AxNode();
	~AxNode();

	void Init();
	bool IsInited() const { return _isInited; }

	void SetParent(AxNode* node);
	AxNode* GetParent() const;
	void AddChild(AxNode* node);
	void RemoveChild(AxNode* node);
	int GetChildsCount() const;
	const vector<AxNode*>& GetChilds() const;
	AxNode* GetChild(int index);

	AxCoord GetLocation() const;
	AxCoord GetGlobalLocation() const;
	void SetLocation(const AxCoord& coord);
	void SetGlobalLocation(const AxCoord& coord);

	// For visual.
	virtual void Redraw();
	virtual void ClearVisual() {}; // TODO.

protected:
	virtual void OnLocationChanged();

protected:
	AxNode* _parent;
	vector<AxNode*> _childs;
	AxCoord _location;

	bool _isInited;

	AxCoord _prevLocation;

};

} // End Ax.