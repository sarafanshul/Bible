// http://graphics.stanford.edu/~seander/bithacks.html
static int  _64_bit_count(ulong i) {
    i = i - ((i >> 1) & 0x5555555555555555UL);
    i = (i & 0x3333333333333333UL) + ((i >> 2) & 0x3333333333333333UL);
    return (int)(unchecked(((i + (i >> 4)) & 0xF0F0F0F0F0F0F0FUL) * 0x101010101010101UL) >> 56);
}

int Kernighan(){
	// 1) Counting bits set, Brian Kernighan's way [O(setBits)]
	unsigned int v; // count the number of bits set in v
	unsigned int c; // c accumulates the total bits set in v
	for (c = 0; v; c++) {
	  v &= v - 1; // clear the least significant bit set
	}
	// Brian Kernighan's method goes through as many iterations as there are set bits. 
	// 	So if we have a 32-bit word with only the high bit set, then it will only go once through the loop.
	return c;
}

int count_bits_parallel(){
	// best
	unsigned int v; // count bits set in this (32-bit value)
	unsigned int c; // store the total here
	static const int S[] = {1, 2, 4, 8, 16}; // Magic Binary Numbers
	static const int B[] = {0x55555555, 0x33333333, 0x0F0F0F0F, 0x00FF00FF, 0x0000FFFF};

	c = v - ((v >> 1) & B[0]);
	c = ((c >> S[1]) & B[1]) + (c & B[1]);
	c = ((c >> S[2]) + c) & B[2];
	c = ((c >> S[3]) + c) & B[3];
	c = ((c >> S[4]) + c) & B[4];
	return c;
}
