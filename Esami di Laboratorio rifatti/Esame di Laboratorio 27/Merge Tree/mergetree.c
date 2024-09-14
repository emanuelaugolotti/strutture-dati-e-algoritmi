//Time: 19 min
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

Node* MergeTree(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return TreeCreateEmpty();
	}
    if (!TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
        return TreeCopy(t1);
    }
    if (TreeIsEmpty(t1) && !TreeIsEmpty(t2)) {
        return TreeCopy(t2);
    }
    const ElemType* val1 = TreeGetRootValue(t1);
    const ElemType* val2 = TreeGetRootValue(t2);
    ElemType sum = *val1 + *val2;
    Node* l = MergeTree(TreeLeft(t1), TreeLeft(t2));
    Node* r = MergeTree(TreeRight(t1), TreeRight(t2));
    Node* out = TreeCreateRoot(&sum, l, r);
    return out;
}