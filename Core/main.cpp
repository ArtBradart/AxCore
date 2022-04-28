#include <conio.h>
#include "AxLabel.h"

int main(int argc, char** argv) 
{
	//setlocale(LC_ALL, "Russian");
	//Ax::MainMenu();
	using namespace Ax;

	AxLabel* testLabel = new AxLabel();
	testLabel->Init();
	Sleep(1000);

	testLabel->SetText("Hello, world");
	Sleep(1000);

	AxNode* testNode = new AxNode();
	testNode->SetLocation({ 3, 3 });
	testNode->AddChild(testLabel);
	testNode->Init();
	Sleep(1000);

	testLabel->SetText("Nice!");
	Sleep(1000);

	_getch();

	return 0;
}