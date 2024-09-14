#include <stdlib.h>
#include <crtdbg.h>

extern char* SolveSuperstring(const char** v, size_t v_size);

int main(void) {
	//char* dizionario[] = { "ABCDH", "DHE", "BCDH", "HEF" };
	char* dizionario[] = { "FEDERICO", "MAURIZIO", "GIANPAOLO" };
	size_t dizionario_size = sizeof(dizionario) / sizeof(char*);

	char* ris = SolveSuperstring(dizionario, dizionario_size);
	
	free(ris);
	_CrtDumpMemoryLeaks();
	return 0;
}