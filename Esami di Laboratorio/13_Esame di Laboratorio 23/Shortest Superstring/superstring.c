#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//date due stringhe C zero terminate assegna al parametro di output overlapping il numero di caratteri di
//massima sovrapposizione e ritorna il puntatore ad una nuova stringa C allocata dinamicamente contenente 
//il risultato della sovrapposizione
static char* Overlap(const char* str1, const char* str2, int* overlapping) {
    const int len1 = (int)strlen(str1);
    const int len2 = (int)strlen(str2);
    const int lenShort = len1 < len2 ? len1 : len2;
    const int lenLong = len1 < len2 ? len2 : len1;
    const char* strShort = len1 < len2 ? str1 : str2;
    const char* strLong = len1 < len2 ? str2 : str1;
    // Check if strShort is a substring of strLong
    if (strstr(strLong, strShort) != NULL) {
        char* res = malloc(lenLong + 1);
        strcpy(res, strLong);
        *overlapping = lenShort;
        return res;
    }
    int maxOverlap = 0;
    bool longGoesFirst = true;
    // Try to put strShort at the end of strLong
    for (int i = lenShort - 1; i > 0; --i) {
        if (strncmp(strLong + lenLong - i, strShort, i) == 0) {
            maxOverlap = i;
            break;
        }
    }
    // Try to put strLong and the end of strShort
    for (int i = lenShort - 1; i > maxOverlap; --i) {
        if (strncmp(strLong, strShort + lenShort - i, i) == 0) {
            if (i > maxOverlap) {
                maxOverlap = i;
                longGoesFirst = false;
            }
            break;
        }
    }
    char* res = malloc(lenLong + lenShort - maxOverlap + 1);
    if (longGoesFirst) {
        strcpy(res, strLong);
        strcpy(res + lenLong, strShort + maxOverlap);
    }
    else {
        strcpy(res, strShort);
        strcpy(res + lenShort, strLong + maxOverlap);
    }
    *overlapping = maxOverlap;
    return res;
}

char* FindStr(const char** v, size_t v_size, size_t* pos1, size_t* pos2) {
    int overlapping_max = -1;
    char* best = NULL;
    if (v_size == 1) {
        size_t len0 = strlen(v[0]);
        best = calloc(len0 + 1, sizeof(char));
        strcpy(best, v[0]);
    }
    size_t start = 0;
    while (start < v_size - 1) {
        for (size_t i = start; i < v_size - 1; ++i) {
           const char* str1 = v[i];
            for (size_t j = start + 1; j < v_size; ++j) {
                const char* str2 = v[j];
                int overlapping_curr;
                char* ris = Overlap(str1, str2, &overlapping_curr);
                if (overlapping_curr > overlapping_max) {
                    overlapping_max = overlapping_curr;
                    char* tmp = best;
                    best = ris;
                    *pos1 = i;
                    *pos2 = j;
                    if (tmp != NULL) {
                        free(tmp);
                    }
                } else {
                    free(ris);
                }
            }
            ++start;
        }
    }
    return best;
}

char* ConfrontaOutConStr(char* out, size_t v_size, const char** v, bool* str_usate, size_t* pos) {
    char* best = NULL;
    int overlapping_max = -1;
    for (size_t i = 0; i < v_size; ++i) {
        if (!str_usate[i]) {
            int overlapping_curr;
            char* ris = Overlap(out, v[i], &overlapping_curr);
            if (overlapping_curr > overlapping_max) {
                char* tmp = best;
                best = ris;
                *pos = i;
                if (tmp != NULL) {
                    free(tmp);
                }
            } else {
                free(ris);
            }
        }
    }
    free(out);
    return best;
}

char* SolveSuperstring(const char** v, size_t v_size) {
    if (v == NULL || v_size == 0) {
        return NULL;
    }
    bool* str_usate = calloc(v_size, sizeof(bool));
    size_t n_usate = 0;
    size_t pos1, pos2;
    char* out = FindStr(v, v_size, &pos1, &pos2);
    n_usate += 2;
    str_usate[pos1] = true;
    str_usate[pos2] = true;
    while (n_usate != v_size) {
        out = ConfrontaOutConStr(out, v_size, v, str_usate, &pos1);
        str_usate[pos1] = true;
        ++n_usate;
    }
    free(str_usate);
    return out;
}