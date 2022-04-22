#include "ArtCore.h"

namespace art {

ArtCore::ArtCore()
{
	//TODO
	//_menuItems.insert("test", EMenu::E_MenuTest

#ifdef 0

	_menuTitles = {
		"",
		"test",
		"test2",
		"exit"
	};

	_menuItems = {
		{ _menuTitles[EMenu::E_MenuTest], EMenu::E_MenuTest },
		{ _menuTitles[EMenu::E_MenuTest2], EMenu::E_MenuTest2 },
		{ _menuTitles[EMenu::E_MenuExit], EMenu::E_MenuExit },
		{ _menuTitles[EMenu::E_MenuNone], EMenu::E_MenuNone }
	};

#endif 
	LiveCycle();
}

ArtCore::~ArtCore()
{
	std::cout << "Thank's!                               " << std::endl;	
	_getch();
}

void ArtCore::LiveCycle()
{
	//std::cout << "Welcome!\n";
	bool bRunning = true;

#ifdef 0
	int select = EMenu::E_MenuNone;
	int target = 1;

	COORD startPosition = { 0, 3 };

	/// First screen
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	std::cout << "/////////////////////////////" << std::endl;
	std::cout << "///     Select option     ///" << std::endl;
	std::cout << "/////////////////////////////" << std::endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
	for (int m = EMenu::E_MenuNone; m < EMenu::countMenues; m++)
	{
		std::cout << "  " << _menuTitles[m] << std::endl;
	}

	//Update console
	auto updateScreen = [this, &hConsole, &startPosition, &select, &target]()
	{
		if (select != target)
		{
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
			SetConsoleCursorPosition(hConsole, COORD{ startPosition.X, startPosition.Y + SHORT(select) });
			std::cout << "  " << _menuTitles[select] << std::ends;
			//-------
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			SetConsoleCursorPosition(hConsole, COORD{ startPosition.X, startPosition.Y + SHORT(target) });
			std::cout << "> " << _menuTitles[target];
			select = target;
		}	
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		SetConsoleCursorPosition(hConsole, COORD{ 0, startPosition.Y + SHORT(EMenu::countMenues) + 1 });

	};
	
	updateScreen();

	while (bRunning)
	{
		EMenu command = EMenu::E_MenuNone;
		switch (_getch())
		{
		case E_ActionUp:
			if (target > 1) target--;
			break;
		case E_ActionDown:
			if (target < EMenu::countMenues - 1) target++;
			break;
		/*
		case E_ActionLeft:
			position.X--;
			break;
		case E_ActionRight:
			position.X++;
			break;
		*/
		case E_ActionEnter:
			command = EMenu(select);
			break;
		case E_ActionEscape:
			bRunning = false;
			break;
		default:
			continue;
		}

		switch (command)
		{
		case E_MenuTest:
			std::cout << "Test accept!                           " << std::endl;
			break;
		case E_MenuTest2:
			std::cout << "Test!                                  " << std::endl;
			break;
		case E_MenuExit:
			bRunning = false;
			break;
		}

		updateScreen();
	}
#endif
}

template<class Obj>
Obj& ArtCore::CreateObject<Obj>()
{
	Obj& obj = new Obj;
	ArtObject& object = dynamic_cast<ArtObject&>(obj)
	if ((obj == nullptr) || (object == nullptr))
	{
		object = nullptr;
		delete(obj);
		return nullptr;
		// Error!
	}

	_objects.push_back(object);
	return object;
}

}

