#include <stdlib.h>
#include <crtdbg.h>

extern int* CacciatorePreda(const char* v, size_t v_size, int u);

int main(void) {
	char v[] = { 'C', 'P', 'C', 'C', 'P', 'P' };
	size_t v_size = sizeof(v) / sizeof(char);

	int* ris;
	ris = CacciatorePreda(v, v_size, 1);

	//Libero la memoria
	free(ris);
	
	_CrtDumpMemoryLeaks();
	return 0;
}