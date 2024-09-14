#include <stdlib.h>
#include <stdbool.h>

extern bool* OptimalIllumination(int M, int R, const int* light,
    size_t light_size);

int main(void) {
    int M = 10, R = 3;
    int light[] = { 2, 7, 9 };
    size_t light_size = sizeof(light) / sizeof(int);

    bool* ris = OptimalIllumination(M, R, light, light_size);
    
    free(ris);
    return 0;
}