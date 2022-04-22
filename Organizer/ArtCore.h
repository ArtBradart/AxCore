#pragma once

#include "Common.h"
#include "ArtObject.h"
#include "ArtFunction.h"

namespace art {

enum EAction
{
	E_ActionUp = 72,
	E_ActionDown = 80,
	E_ActionLeft = 75,
	E_ActionRight = 77,
	E_ActionEnter = 13,
	E_ActionEscape = 27
};

class ArtCore
{
public:
	ArtCore();
	~ArtCore();

	void LiveCycle();

	template<class Obj> 
	Obj& CreateObject();
	void DestroyObject(ArtObject& obj);

	ArtFunction& CreateFunction(void(*func)(void));
	void DestroyFunction(ArtFunction& func);

protected:


private:
	static std::vector<std::string> _menuTitles; //Todo: delete legacy
	static std::vector<ArtObject*> _objects;
	static std::map<std::string, ArtFunction*> _functions;
};

}