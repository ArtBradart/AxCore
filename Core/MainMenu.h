#include "Common.h"
#include "AxMenu.h"

namespace Ax {

class MainMenu
{
public:
	MainMenu();
	~MainMenu();

	bool ConstructMenu(AxMenu& list);

protected:
	void Begin();
	bool Tick();

private:
	HANDLE _hConsole;

	bool _Running;
};

} // End Ax.