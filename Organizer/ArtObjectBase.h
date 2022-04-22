#pragma once

#include "ArtCore.h"

namespace art {

class ArtObjectBase
{
public:
	ArtObjectBase();
	~ArtObjectBase();

	virtual void BeginPlay() = 0;
	virtual void EndPlay() = 0;
	virtual void Tick() = 0;

	template<class Obj> 
	Obj& At<Obj>(ArtObject& object);

	void SetCore(ArtCore* core) { Core = core; } 
	ArtCore* GetCore() const { return Core; }

protected:
	ArtCore* Core;

};

}