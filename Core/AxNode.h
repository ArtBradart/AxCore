#pragma once

#include <vector>
#include "AxCoord.h"

namespace Ax {

using namespace std;

class AxNode
{
public:
	AxNode(AxNode* parent = nullptr, const AxCoord& location = {}, const AxCoord& bounds = {});
	~AxNode();

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

	AxCoord GetBounds() const;
	void SetBounds(const AxCoord& coord);

protected:
	void OnLocationChanged(const AxCoord& prewCoord);
	void OnBoundsChanged(const AxCoord& prewCoord);

protected:
	AxNode* _parent;
	vector<AxNode*> _childs;
	AxCoord _location;
	AxCoord _bounds;

};

} // End Ax.