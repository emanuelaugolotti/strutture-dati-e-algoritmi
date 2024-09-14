#include "tree.h"

bool EsisteCoppia(const Node* t, const Node* n1, const ElemType* val1, int n) {
	if (TreeIsEmpty(t)) {
		return false;
	}
	bool ris1 = false;
	if (t != n1) {
		const ElemType* val2 = TreeGetRootValue(t);
		ElemType sum = *val1 + *val2;
		if (ElemCompare(&sum, &n) == 0) {
			ris1 = true;
		}
	}
	bool ris2 = EsisteCoppia(TreeLeft(t), n1, val1, n);
	bool ris3 = EsisteCoppia(TreeRight(t), n1, val1, n);
	return ris1 || ris2 || ris3;
}

void EsploraAlbero(const Node* root, const Node* t, int n, bool* risposta) {
	if (TreeIsEmpty(t)) {
		return;
	}
	const ElemType* val1 = TreeGetRootValue(t);
	bool esiste = EsisteCoppia(root, t, val1, n);
	if (esiste) {
		*risposta = true;
	}
	EsploraAlbero(root, TreeLeft(t), n, risposta);
	EsploraAlbero(root, TreeRight(t), n, risposta);
}

bool CheckSumN(const Node* t, int n) {
	if (TreeIsEmpty(t)) {
		return false;
	}
	bool risposta = false;
	EsploraAlbero(t, t, n, &risposta);
	return risposta;
}