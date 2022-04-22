#include "ArtObject.h"

namespace art {
	
ArtObject::ArtObject()
	: _parent(nullptr)
{
}

ArtObject::~ArtObject()
{
	EndPlay();
}

void ArtObject::BeginPlay()
{
}

void ArtObject::EndPlay()
{
}

void ArtObject::Tick()
{
}

void ArtObject::TickComponents()
{
	for (ArtObjectBase* component : _components)
	{
		component->Tick();
	}
}

void ArtObject::AddComponent(ArtObjectBase * component)
{
	if (component == nullptr) return;
	_components.push_back(component);
	component->BeginPlay();
}

void ArtObject::SetParent(ArtObjectBase * parent)
{
	if (parent == nullptr) return;
	_parent = parent;
}

}