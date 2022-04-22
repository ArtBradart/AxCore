#pragma once

#include "ArtObjectBase.h"

namespace art {

class ArtObject : public ArtObjectBase
{
	typedef ArtObjectBase Super;

public:
	ArtObject();
	~ArtObject();

	virtual void BeginPlay();
	virtual void EndPlay();
	virtual void Tick();

	void AddComponent(ArtObjectBase* component);
	void SetParent(ArtObjectBase* parent);

protected:
	void TickComponents();

protected:
	ArtObjectBase* _parent;
	std::vector<ArtObjectBase*> _components;
};

}