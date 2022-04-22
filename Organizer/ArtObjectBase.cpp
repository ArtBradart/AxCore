#include "ArtObjectBase.h"

namespace art {

ArtObjectBase::ArtObjectBase()
	: Core(nullptr)
{
}

template<class Obj1, class Obj2>
Obj1& ArtObjectBase::At(Obj2& object)
{
	Obj1& obj = dynamic_cast<Obj1&>(object);
}

}