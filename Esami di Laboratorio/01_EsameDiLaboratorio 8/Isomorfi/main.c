#include "tree.h"
#include <stdbool.h>

extern bool Isomorfi(const Node* t1, const Node* t2);

Node* TreeInsertBinOrd(const ElemType* e, Node* n) {
    if (TreeIsEmpty(n)) {
        return TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
    }
    Node* root = n;

    while (true) {
        if (ElemCompare(e, TreeGetRootValue(n)) < 0) {
            if (TreeIsEmpty(TreeLeft(n))) {
                n->left = TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
                break;
            }
            else {
                n = TreeLeft(n);
            }
        }
        else {
            if (TreeIsEmpty(TreeRight(n))) {
                n->right = TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
                break;
            }
            else {
                n = TreeRight(n);
            }
        }
    }

    return root;
}

int main(void) {
    
    int v[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    Node* tree1 = TreeCreateRoot(v,
        TreeCreateRoot(v + 1,
            TreeCreateRoot(v + 3,
                TreeCreateRoot(v + 6, NULL, NULL), TreeCreateRoot(v + 7, NULL, NULL)),
            TreeCreateRoot(v + 4, NULL, NULL)),
        TreeCreateRoot(v + 2, TreeCreateRoot(v + 5, NULL, NULL), NULL));
        
    TreeWriteStdoutPreOrder(tree1);

    int e[] = { 1, 3, 2, 6, 4, 5, 8, 7 };
    Node* tree2 = TreeCreateRoot(v,
        TreeCreateRoot(e + 1, TreeCreateRoot(e + 3, NULL, NULL), NULL),
        TreeCreateRoot(e + 2,
            TreeCreateRoot(e + 4,
                TreeCreateRoot(e + 6, NULL, NULL),
             TreeCreateRoot(e + 7, NULL, NULL)),
            TreeCreateRoot(e + 5, NULL, NULL)));
    
    TreeWriteStdoutPreOrder(tree2);

    bool ris = Isomorfi(tree1, tree2);

	TreeDelete(tree1);
	TreeDelete(tree2);
    
    return 0;
}