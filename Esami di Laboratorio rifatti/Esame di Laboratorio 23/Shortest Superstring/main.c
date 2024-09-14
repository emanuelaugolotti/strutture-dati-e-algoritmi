#include <stdlib.h>
#include <crtdbg.h>

extern char* SolveSuperstring(const char** v, size_t v_size);

int main(void) {
	/*char* v[] = { "ABCDH", "DHE", "BCDH", "HEF" };*/
	char* v[] = { "FEDERICO", "MAURIZIO", "GIANPAOLO" };
	size_t v_size = sizeof(v) / sizeof(char*);

	char* ris = SolveSuperstring(v, v_size);

	free(ris);
	_CrtDumpMemoryLeaks();
	return 0;
}