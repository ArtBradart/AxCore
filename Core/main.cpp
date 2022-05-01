#include <conio.h>
#include "AxTestMenu.h"

int main(int argc, char** argv) 
{
	//setlocale(LC_ALL, "Russian");
	//Ax::MainMenu();
	using namespace Ax;

	AxTestMenu* testMenu = new AxTestMenu();
	testMenu->Init();
	testMenu->Update();

	_getch();

	return 0;
}