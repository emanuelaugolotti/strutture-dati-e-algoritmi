//Time: 24 min
#include "minheap.h"

bool CondizioneRispettata(size_t p_pos, ElemType* data, size_t data_size) {
	ElemType p_val = data[p_pos];
	int l_pos = HeapLeft(p_pos);
	int r_pos = HeapRight(p_pos);
	ElemType l_val = data[l_pos];
	ElemType r_val = data[r_pos];
	if (l_pos >= (int)data_size) {
		l_val = p_val;
	}
	if (r_pos >= (int)data_size) {
		r_val = p_val;
	}
	if (ElemCompare(&l_val, &p_val) >= 0 && ElemCompare(&r_val, &p_val) >= 0) {
		return true;
	}
	return false;
}

bool IsHeap(const Heap* h) {
	if (h->data == NULL) {
		return false;
	}
	if (HeapIsEmpty(h) || h->size == 1) {
		return true;
	}
	for (size_t i = 0; i <= h->size / 2 - 1; ++i) {
		if (!CondizioneRispettata(i, h->data, h->size)) {
			return false;
		}
	}
	return true;
}