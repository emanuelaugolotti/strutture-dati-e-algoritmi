#include <crtdbg.h>
#include <stdio.h>

extern void DnaAlignment(const char* filename);

int main(void) {
	DnaAlignment("input.txt");
	_CrtDumpMemoryLeaks();
	return 0;
}