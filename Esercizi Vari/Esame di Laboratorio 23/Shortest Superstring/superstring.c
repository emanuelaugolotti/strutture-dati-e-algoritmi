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



char* ScegliStringa(const char** v, size_t v_size, bool* usati, char* out, size_t* pos) {
    char* str_out = NULL;
    int best_overlapping = 0;
    for (size_t i = 0; i < v_size; ++i) {
        if (!usati[i]) {
            const char* str = v[i];
            int curr_overlapping;
            char* ris = Overlap(out, str, &curr_overlapping);
            if (curr_overlapping < best_overlapping) {
                free(ris);
            } else {
                char* tmp = str_out;
                str_out = ris;
                best_overlapping = curr_overlapping;
                *pos = i;
                if (tmp != NULL) {
                    free(tmp);
                }
            }
        }
    }
    return str_out;
}

char* StringaPiuLunga(const char** v, size_t v_size, bool* usati) {
    char* out = NULL;
    size_t pos;
    size_t lenbest = 0;
    for (size_t i = 0; i < v_size; ++i) {
        size_t lencurr = strlen(v[i]);
        if (lencurr > lenbest) {
            pos = i;
            lenbest = lencurr;
        }
    }
    out = malloc((lenbest + 1) * sizeof(char));
    strcpy(out, v[pos]);
    usati[pos] = true;
    return out;
}

char* SolveSuperstring(const char** v, size_t v_size) {
    if (v == NULL || v_size == 0) {
        return NULL;
    }
    bool* usati = calloc(v_size, sizeof(bool));
    char* out = StringaPiuLunga(v, v_size, usati);
    size_t count = 0;
    while (count < v_size - 1) {
        size_t pos_stringapresa;
        char* tmp = out;
        out = ScegliStringa(v, v_size, usati, out, &pos_stringapresa);
        free(tmp);
        usati[pos_stringapresa] = true;
        ++count;
    }
    free(usati);
    return out;
}