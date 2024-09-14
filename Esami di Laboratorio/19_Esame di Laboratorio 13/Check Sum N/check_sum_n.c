#include "tree.h"
#include <stdbool.h>
#include <stdlib.h>

void ContaNodi(const Node* t, size_t* count) {
	if (TreeIsEmpty(t)) {
		return;
	}
	++(*count);
	ContaNodi(TreeLeft(t), count);
	ContaNodi(TreeRight(t), count);
}

void EsisteSomma(const Node* t, int n, size_t num_nodo, size_t* count, bool* ris_somma, int val) {
	if (TreeIsEmpty(t)) {
		return;
	}
	++(*count);
	if (*count != num_nodo) {
		ElemType val_curr = ElemCopy(TreeGetRootValue(t));
		int somma_curr = val + val_curr;
		if (somma_curr == n) {
			*ris_somma = true;
			return;
		}
	}
	EsisteSomma(TreeLeft(t), n, num_nodo, count, ris_somma, val);
	EsisteSomma(TreeRight(t), n, num_nodo, count, ris_somma, val);
}

void CheckSumNRec(const Node* t, int n, bool* ris, size_t* count, const Node* root) {
	if (TreeIsEmpty(t)) {
		return;
	}
	++(*count);
	ElemType val = ElemCopy(TreeGetRootValue(t));
	bool ris_somma = false;
	size_t numero_nodo = 0;
	EsisteSomma(root, n, *count, &numero_nodo, &ris_somma, val);
	if (ris_somma) {
		*ris = true;
		return;
	}
	CheckSumNRec(TreeLeft(t), n, ris, count, root);
	CheckSumNRec(TreeRight(t), n, ris, count, root);
}

bool CheckSumN(const Node* t, int n) {
	if (TreeIsEmpty(t)) {
		return false;
	}
	size_t count = 0;
	ContaNodi(t, &count);
	if (count <= 2) {
		return false;
	}
	bool ris = false;
	size_t numero_nodo = 0;
	const Node* root = t;
	CheckSumNRec(t, n, &ris, &numero_nodo, root);
	return ris;
}