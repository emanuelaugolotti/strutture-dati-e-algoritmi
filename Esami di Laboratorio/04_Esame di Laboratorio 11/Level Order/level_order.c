//Time: 1h 7min

#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void StampaLivello(const Node* t, int* livello_dastampare, int* nodoprecstampato, int* nododastampare, int i) {
	if (TreeIsEmpty(t)) {
		return;
	}

	if ((i == *livello_dastampare) && (*nododastampare > *nodoprecstampato)) {
		const ElemType* value = TreeGetRootValue(t);
		if (i != 0) {
			printf(" ");
		}
		printf("%d", *value);
		++(*nododastampare);
		++(*nodoprecstampato);
	}

	StampaLivello(TreeLeft(t), livello_dastampare, nodoprecstampato, nododastampare, i + 1);
	StampaLivello(TreeRight(t), livello_dastampare, nodoprecstampato, nododastampare, i + 1);
}

void LevelOrderRec(const Node* t, int* livello_dastampare, int* livello_precstampato, int i, const Node* tmp) {
	if (TreeIsEmpty(t)) {
		return;
	}
	
	if (*livello_dastampare == i && *livello_dastampare > *livello_precstampato) {
		//chiamo la funzione che stampa tutti i nodi del livello i
		int nodoprecstampato = -1;
		int nododastampare = 0;
		StampaLivello(tmp, livello_dastampare, &nodoprecstampato, &nododastampare, 0);
		++(*livello_dastampare);
		++(*livello_precstampato);
	}
	
	LevelOrderRec(TreeLeft(t), livello_dastampare, livello_precstampato, i + 1, tmp);
	LevelOrderRec(TreeRight(t), livello_dastampare, livello_precstampato, i + 1, tmp);
}

void LevelOrder(const Node* t) {

	int livello_dastampare = 0;
	int livello_precstampato = -1;
	LevelOrderRec(t, &livello_dastampare, &livello_precstampato, 0, t);
}