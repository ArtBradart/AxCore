#include "ArtCore.h"
/*
	Entry program file
*/
using namespace art;

int main(int argc, char** argv)
{
	ArtCore& core = ArtCore();
	auto object = core.CreateObject<ArtObject>();

	return 0;
}