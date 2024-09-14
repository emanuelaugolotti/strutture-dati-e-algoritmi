#include "tree.h"
#include <stdlib.h>

void ContaNodi(Node* t, int* count) {
	if (TreeIsEmpty(t)) {
		return;
	}
	++(*count);
	ContaNodi(TreeLeft(t), count);
	ContaNodi(TreeRight(t), count);
}

void PopolaVettNext(Node* t, Node* next[], int* count) {
	if (TreeIsEmpty(t)) {
		return;
	}
	PopolaVettNext(TreeRight(t), next, count);
	next[*count] = t;
	--(*count);
	PopolaVettNext(TreeLeft(t), next, count);
}

void PopolaCampiNext(Node* t, Node* next[], int* count) {
	if (TreeIsEmpty(t)) {
		return;
	}
	PopolaCampiNext(TreeLeft(t), next, count);
	t->next = next[*count];
	++(*count);
	PopolaCampiNext(TreeRight(t), next, count);
}

void PopulatingNext(Node* t) {
	if (TreeIsEmpty(t)) {
		return;
	}
	int n = 0;
	ContaNodi(t, &n);
	Node** next = malloc(n * sizeof(Node*));
	int count = n - 1;
	PopolaVettNext(t, next, &count);
	next = realloc(next, (n + 1) * sizeof(Node*));
	next[n] = NULL;
	count = 1;
	PopolaCampiNext(t, next, &count);
	free(next);
}