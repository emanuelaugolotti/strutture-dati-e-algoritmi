#include "tree.h"
#include <stdio.h>

void StampaLivello(const Node* t, int livello, int i) {
	if (TreeIsEmpty(t)) {
		return;
	}
	if (livello == i) {
		const ElemType* val = TreeGetRootValue(t);
		printf("%i ", *val);
	}
	StampaLivello(TreeLeft(t), livello, i + 1);
	StampaLivello(TreeRight(t), livello, i + 1);
}

void ContaLivelli(const Node* t, int curr_liv, int* tot_liv) {
	if (TreeIsEmpty(t)) {
		return;
	}
	if (curr_liv > *tot_liv) {
		++(*tot_liv);
	}
	ContaLivelli(TreeLeft(t), curr_liv + 1, tot_liv);
	ContaLivelli(TreeRight(t), curr_liv + 1, tot_liv);
}

void LevelOrder(const Node* t) {
	if (TreeIsEmpty(t)) {
		return;
	}
	int n = 0;
	ContaLivelli(t, 1, &n);
	for (int i = 0; i < n; ++i) {
		StampaLivello(t, i, 0);
	}
}