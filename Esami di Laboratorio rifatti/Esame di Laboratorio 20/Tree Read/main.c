#include "tree.h"

extern Node* TreeRead(const char* filename);

int main(void) {
	Node* t = TreeRead("albero1.txt");
	TreeWriteStdoutPostOrder(t);
	TreeDelete(t);
	return 0;
}