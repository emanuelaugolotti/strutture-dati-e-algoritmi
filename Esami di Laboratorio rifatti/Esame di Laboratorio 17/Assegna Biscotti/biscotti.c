//Time: 1h
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Assegnati {
    size_t* b;
    int* gol_residua;
    int n;  //numero bambini soddisfatti
} Assegnati;

void LiberaMemoria(Assegnati curr, Assegnati* best) {
    free(curr.b);
    free(curr.gol_residua);
    free(best->b);
    free(best->gol_residua);
    free(best);
}

bool BambinoSoddisfatto(int* gol_residua, size_t bam_index, int gol_bis, int* r) {
    *r = gol_residua[bam_index] - gol_bis;
    if (*r <= 0) {
        return true;
    }
    return false;
}

void AssegnaBiscottiRec(const int* bam, size_t bam_size, const int* bis, size_t bis_size, Assegnati curr,
                Assegnati* best, size_t i) {
    if (i == bis_size) {
        if (best->n < curr.n) {
            best->n = curr.n;
            memcpy(best->gol_residua, curr.gol_residua, bam_size * sizeof(int));
            memcpy(best->b,curr.b,bis_size*sizeof(size_t));
        }
        return;
    }
    for (size_t bam_index = 0; bam_index < bam_size; ++bam_index) {
        if (curr.gol_residua[bam_index] > 0) {
            curr.b[i] = bam_index;
            int r;
            int gol_prev = curr.gol_residua[bam_index];
            bool soddisfatto = BambinoSoddisfatto(curr.gol_residua, bam_index, bis[i], &r);
            curr.gol_residua[bam_index] = r;
            if (soddisfatto) {
                ++curr.n;
            }
            AssegnaBiscottiRec(bam, bam_size, bis, bis_size, curr, best, i + 1);
            if (soddisfatto) {
                --curr.n;
            }
            curr.gol_residua[bam_index] = gol_prev;
        }
    }
}

int AssegnaBiscotti(const int* bam, size_t bam_size, const int* bis, size_t bis_size) {
    if (bam == NULL || bis == NULL || bam_size == 0 || bis_size == 0) {
        return 0;
    }
    Assegnati curr;
    curr.n = 0;
    curr.b = malloc(bis_size * sizeof(size_t));
    curr.gol_residua = malloc(bam_size * sizeof(int));
    memcpy(curr.gol_residua, bam, bam_size * sizeof(int));
    Assegnati* best = malloc(sizeof(Assegnati));
    best->n = 0;
    best->b = malloc(bis_size * sizeof(size_t));
    best->gol_residua = malloc(bam_size * sizeof(int));
    AssegnaBiscottiRec(bam, bam_size, bis, bis_size, curr, best, 0);
    int bam_soddisfatti = best->n;
    LiberaMemoria(curr, best);
    return bam_soddisfatti;
}