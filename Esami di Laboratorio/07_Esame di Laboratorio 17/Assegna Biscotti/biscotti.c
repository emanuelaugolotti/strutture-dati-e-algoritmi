//Time: 49 min
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Assegnati {
    size_t* bis_assegnati;
    bool* bam_soddisfatti;
    size_t n_accontentati; //numero di bambini accontentati
};
typedef struct Assegnati Assegnati;

void AssegnaBiscottiRec(int* gol_rimanente, size_t bam_size, const int* bis, size_t bis_size, Assegnati* best,
    Assegnati curr, size_t i) {
    if (i == bis_size) {
        if (curr.n_accontentati > best->n_accontentati) {
            best->n_accontentati = curr.n_accontentati;
            memcpy(best->bis_assegnati, curr.bis_assegnati, bis_size * sizeof(size_t));
            memcpy(best->bam_soddisfatti, curr.bam_soddisfatti, bam_size * sizeof(bool));
        }
        return;
    }
    for (size_t indexbam = 0; indexbam < bam_size; ++indexbam) {
        bool soddisfatto = false;
        if (!curr.bam_soddisfatti[indexbam]) {
            curr.bis_assegnati[i] = indexbam;
            gol_rimanente[indexbam] -= bis[i];
            if (gol_rimanente[indexbam] <= 0) {   
                curr.bam_soddisfatti[indexbam] = true;
                ++(curr.n_accontentati);
                soddisfatto = true;
            }
            AssegnaBiscottiRec(gol_rimanente, bam_size, bis, bis_size, best, curr, i + 1);
            gol_rimanente[indexbam] += bis[i];
            if (soddisfatto) {
                curr.bam_soddisfatti[indexbam] = false;
                --(curr.n_accontentati);
            }
        }
    }
    AssegnaBiscottiRec(gol_rimanente, bam_size, bis, bis_size, best, curr, bis_size);
}

int AssegnaBiscotti(const int* bam, size_t bam_size, const int* bis, size_t bis_size) {
    if (bam == NULL || bam_size == 0 || bis == NULL || bis_size == 0) {
        return 0;
    }
    int* gol_rimanente = malloc(bam_size * sizeof(int));
    memcpy(gol_rimanente, bam, bam_size * sizeof(int));
    Assegnati best;
    best.n_accontentati = 0;
    best.bis_assegnati = malloc(bis_size * sizeof(size_t));
    best.bam_soddisfatti = calloc(bam_size, sizeof(bool));
    Assegnati curr;
    curr.n_accontentati = 0;
    curr.bis_assegnati = malloc(bis_size * sizeof(size_t));
    curr.bam_soddisfatti = calloc(bam_size, sizeof(bool));
    
    AssegnaBiscottiRec(gol_rimanente, bam_size, bis, bis_size, &best, curr, 0);
    
    free(best.bis_assegnati);
    free(best.bam_soddisfatti);
    free(curr.bam_soddisfatti);
    free(curr.bis_assegnati);
    free(gol_rimanente);
    return (int)best.n_accontentati;
}