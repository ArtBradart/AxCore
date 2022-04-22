#include "Common.h"
#include "Menu.h"

class MainMenu
{
public:
	MainMenu();
	~MainMenu();

	bool ConstructMenu(Menu& list);

protected:
	void Begin();
	bool Tick();

private:
	HANDLE _hConsole;

	bool _Running;
};