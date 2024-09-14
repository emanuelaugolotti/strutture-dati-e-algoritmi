#include "alpine_road.h"
#include <crtdbg.h>

int main(void) {
	Point percorso[] = { { 0,10}, { 40,19}, { 60,19}, { 110,25}, { 170,17} };
	//Point percorso[] = { { 0,18}, { 50,31}, { 55,46}, { 120,46}, { 130,24}, {150,5}, {200,5}, {210, 5} };
	//Point percorso[] = { { 0,18}, { 50,32} };

	size_t percorso_size = sizeof(percorso) / sizeof(Point);

	int ris;
	ris = FindPath(percorso, percorso_size, 10);
	//printf("\n");
	//ris = FindPath(percorso, percorso_size, 0);
	
	//ris = FindPath(percorso, percorso_size, 10);
	/*ris = FindPath(percorso, percorso_size, 20);*/
	//ris = FindPath(percorso, percorso_size, 0);

	//ris = FindPath(percorso, percorso_size, 5);

	printf("Lunghezza = %i", ris);
	_CrtDumpMemoryLeaks();
	return 0;
}