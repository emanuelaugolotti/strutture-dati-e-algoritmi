#include <stdlib.h>
#include <crtdbg.h>

extern int AssegnaBiscotti(const int* bam, size_t bam_size, const int* bis, size_t bis_size);

int main(void) {
    /*int bam[] = { 10, 10, 10 };
    size_t bam_size = sizeof(bam) / sizeof(int);
    int  bis[] = { 10, 12, 14 };
    size_t bis_size = sizeof(bis) / sizeof(int);
    int ris = AssegnaBiscotti(bam, bam_size, bis, bis_size);*/

   /* int bam[] = { 10, 20, 30 };
    size_t bam_size = sizeof(bam) / sizeof(int);
    int  bis[] = { 10, 6, 7, 8 };
    size_t bis_size = sizeof(bis) / sizeof(int);
    int ris = AssegnaBiscotti(bam, bam_size, bis, bis_size);*/

    int bam[] = { 10, 20, 30 };
    size_t bam_size = sizeof(bam) / sizeof(int);
    int  bis[] = { 10, 50 };
    size_t bis_size = sizeof(bis) / sizeof(int);
    int ris = AssegnaBiscotti(bam, bam_size, bis, bis_size);
   
    _CrtDumpMemoryLeaks();
    return 0;
}