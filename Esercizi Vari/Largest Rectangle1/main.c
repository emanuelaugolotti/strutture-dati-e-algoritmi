

#include <stdlib.h>
#include <crtdbg.h>

extern int LargestRectangle(const int* buildings, size_t buildings_size);

int main(void) {
	//int buildings[] = { 1, 3, 3, 2, 4, 1, 5, 3, 2 };		//ris = 9
	//int buildings[] = { 3, 3, 3, 4, 4, 4, 1, 3, 1, 2, 8, 9, 1 };	//ris= 18
	//int buildings[] = { 2, 2, 30, 20, 20, 2, 2, 1 };	//ris = 60
	//int buildings[] = { 2, 1, 2 };	//ris = 3
	//int buildings[] = { 1, 2, 3, 4, 5, 11 };	//ris = 12
	//int buildings[] = { 10, 21 };	//ris = 21
	//int buildings[] = { 11, 21 };	//ris = 22
	//int buildings[] = { 10, 1, 2, 3, 4, 5, 6, 7 };	//ris = 16
	int buildings[] = { 10, 1, 2, 3, 3, 5, 6, 7 };	//ris = 15
	
	size_t buildings_size = sizeof(buildings) / sizeof(int);

	int ris = LargestRectangle(buildings, buildings_size);

	_CrtDumpMemoryLeaks();
	return 0;
}