#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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

char* GetBest(const char* str, const char** v, size_t v_size, bool* usati, size_t* posbest, 
              int* bestoverlapping) {
    int bestcount = 0;
    char* beststr = NULL;
    for (size_t i = 0; i < v_size; ++i) {
        if (!usati[i]) {
            int overlapping;
            char* curr = Overlap(str, v[i], &overlapping);
            if (bestcount <= overlapping) {
                char* tmp = beststr;
                bestcount = overlapping;
                beststr = curr;
                *posbest = i;
                *bestoverlapping = overlapping;
                free(tmp);
            } else {
                free(curr);
            }
        }
    }
    return beststr;
}

char* GetPrimaCoppia(const char** v, size_t v_size, size_t* pos1, size_t* pos2) {
    bool* usati = calloc(v_size, sizeof(bool));
    int bestcount = 0;
    char* beststr = NULL;
    for (size_t i = 0; i < v_size; ++i) {
        size_t pos;
        int overlapping;
        usati[i] = true;
        char* curr = GetBest(v[i], v, v_size, usati, &pos, &overlapping);
        if (bestcount <= overlapping) {
            char* tmp = beststr;
            bestcount = overlapping;
            beststr = curr;
            *pos1 = i;
            *pos2 = pos;
            free(tmp);
        } else {
            free(curr);
        }
        usati[i] = false;
    }
    free(usati);
    return beststr;
}

char* SolveSuperstring(const char** v, size_t v_size) {
    if (v == NULL || v_size == 0) {
        return NULL;
    }
    char* out = NULL;
    bool* usati = calloc(v_size, sizeof(bool));
    size_t pos1, pos2;
    out = GetPrimaCoppia(v, v_size, &pos1, &pos2);
    usati[pos1] = true, usati[pos2] = true;
    size_t count = 2;
    while (count < v_size) {
        size_t pos;
        int overlapping;
        char* tmp = out;
        out = GetBest(out, v, v_size, usati, &pos, &overlapping);
        free(tmp);
        usati[pos] = true;
        ++count;
    }
    free(usati);
    return out;
}