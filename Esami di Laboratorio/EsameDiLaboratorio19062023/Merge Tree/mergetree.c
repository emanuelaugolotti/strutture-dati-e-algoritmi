#include "tree.h"

Node* TreeCopy(const Node* t) {
    if (TreeIsEmpty(t)) {
        return NULL;
    }
    Node* n = TreeCreateRoot(TreeGetRootValue(t), NULL, NULL);
    n->left = TreeCopy(TreeLeft(t));
    n->right = TreeCopy(TreeRight(t));
    return n;
}

//void MergeTreeRec(const Node* t1, const Node* t2) {
//    if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
//
//    }
//}

//void Esplora(const Node* t, ElemType* curr) {
//    if (TreeIsEmpty(t)) {
//        curr = NULL;
//    }
//    ElemType val = ElemCopy(TreeGetRootValue(t));
//    
//}

Node* MergeTree(const Node* t1, const Node* t2) {
    if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
        return NULL;
    }
    if (TreeIsEmpty(t1)) {
        return TreeCopy(t2);
    }
    if (TreeIsEmpty(t2)) {
        return TreeCopy(t2);
    }
    Node* out = TreeCreateEmpty();

	return out;
}