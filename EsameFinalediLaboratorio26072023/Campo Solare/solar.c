#include <stdlib.h>
#include <math.h>

int GetAreaMax(int* area_rimasta) {
	int areamax_sqr = (int)floor(sqrt(*area_rimasta));
	int areamax = pow(areamax_sqr, 2);
	*area_rimasta -= areamax;
	return areamax;
}

int* SolarCut(int A, size_t* sol_size) {
	int* sol = NULL;
	*sol_size = 0;
	int area_rimasta = A;
	while (area_rimasta > 0) {
		int areamax = GetAreaMax(&area_rimasta);
		++(*sol_size);
		sol = realloc(sol, *sol_size * sizeof(int));
		sol[*sol_size - 1] = areamax;
	}
	return sol;
}