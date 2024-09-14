#include <stdlib.h>
#include <stdbool.h>
#include <crtdbg.h>

extern bool* OptimalIllumination(int M, int R, const int* light, size_t light_size);

int main(void) {
	int light[] = { 2, 7, 9 };
	/*int light[] = { 2, 3, 7, 9 };*/
	size_t light_size = sizeof(light) / sizeof(int);
	
	bool* ris1 = OptimalIllumination(10, 3, light, light_size);
	free(ris1);
	
	/*bool* ris2 = OptimalIllumination(10, 2, light, light_size);
	free(ris2);*/

	/*bool* ris3 = OptimalIllumination(10, 2, light, light_size);
	free(ris3);*/
	
	_CrtDumpMemoryLeaks();
	return 0;
}