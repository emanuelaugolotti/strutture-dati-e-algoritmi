//Time: 36min
#include "tree.h"

void EsistePercorsoRec(Node* t, const ElemType* target, ElemType somma, bool* ris) {
	if (TreeIsEmpty(t)) {
		if (somma == *target) {
			*ris = true;
		}
		return;
	}
	ElemType value = ElemCopy(TreeGetRootValue(t));
	somma += value;
	EsistePercorsoRec(TreeLeft(t), target, somma, ris);
	EsistePercorsoRec(TreeRight(t), target, somma, ris);
}

bool PercorsoSomma(Node* t, const ElemType* target) {
	if (TreeIsEmpty(t) || target == NULL) {
		return false;
	}
	bool ris = false;
	EsistePercorsoRec(t, target, 0, &ris);
	return ris;
}