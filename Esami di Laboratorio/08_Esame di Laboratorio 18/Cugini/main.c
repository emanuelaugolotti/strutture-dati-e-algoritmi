#include "tree.h"
#include <stdbool.h>
#include <stdlib.h>

extern bool Cugini(const Node* t, int a, int b);

// Per ogni nodo (elemento `i`-esimo del vettore) considero come figlio sinistro
// l'elemento del vettore di indice `i * 2 + 1`, e come figlio destro l'elemento
// di indice `i * 2 + 2`.
Node* TreeCreateFromVectorRec(const int* v, size_t v_size, int i) {
    if (i >= (int)v_size) {
        return NULL;
    }

    Node* l = TreeCreateFromVectorRec(v, v_size, i * 2 + 1);
    Node* r = TreeCreateFromVectorRec(v, v_size, i * 2 + 2);

    return TreeCreateRoot(&v[i], l, r);
}

Node* TreeCreateFromVector(const int* v, size_t v_size) {
    return TreeCreateFromVectorRec(v, v_size, 0);
}

int main(void) {
    int v[] = { 1, 2, 5, 3, 4, 6, 8 };
    size_t v_size = sizeof(v) / sizeof(int);
    Node* tree = TreeCreateEmpty();

    tree = TreeCreateFromVector(v, v_size);
    TreeWriteStdoutPostOrder(tree);

    bool ris;
    /*ris = Cugini(tree, 3, 4);*/
    ris = Cugini(tree, 3, 6);
    ris = Cugini(tree, 4, 6);

    TreeDelete(tree);
    return 0;
}
