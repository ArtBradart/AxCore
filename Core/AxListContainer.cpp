#include "AxListContainer.h"

namespace Ax {

AxListContainer::AxListContainer()
{}

void AxListContainer::Add(AxNode* item)
{
	AxCoord loc = item->GetLocation();
	loc.y = GetChildsCount();
	item->SetLocation(loc);
	AddChild(item);
}

void AxListContainer::Remove(AxNode* item)
{
	int index = GetChildIndex(item);
	if (index < 0) return;

	RemoveChild(item);
	for (int i = index; i < GetChildsCount(); i++)
	{
		AxNode* child = GetChild(i);
		AxCoord loc = child->GetLocation();
		loc.y = GetChildsCount();
		child->SetLocation(loc);
	}
}

} // End Ax.