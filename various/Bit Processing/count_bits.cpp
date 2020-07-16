#include<bits/stdc++.h>

using namespace std;

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

int count_bits_32(){
		// The best method for counting bits in a 32-bit integer v is the following:

	unsigned int v; // count bits set in this (32-bit value)
	unsigned int c; // store the total here
	v = v - ((v >> 1) & 0x55555555);                    // reuse input as temporary
	v = (v & 0x33333333) + ((v >> 2) & 0x33333333);     // temp
	c = ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; // count

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
	/*
		The B array, expressed as binary, is:
		B[0] = 0x55555555 = 01010101 01010101 01010101 01010101
		B[1] = 0x33333333 = 00110011 00110011 00110011 00110011
		B[2] = 0x0F0F0F0F = 00001111 00001111 00001111 00001111
		B[3] = 0x00FF00FF = 00000000 11111111 00000000 11111111
		B[4] = 0x0000FFFF = 00000000 00000000 11111111 11111111
		
		We can adjust the method for larger integer sizes 
			by continuing with the patterns for the Binary Magic Numbers, 
			B and S. If there are k bits, then we need the 
			arrays S and B to be ceil(lg(k)) elements long, 
			and we must compute the same number of expressions for c as S or B are long. 
			For a 32-bit v, 16 operations are used.
	*/
}


int count_one(int x) {
    x = (x & (0x55555555)) + ((x >> 1) & (0x55555555));
    x = (x & (0x33333333)) + ((x >> 2) & (0x33333333));
    x = (x & (0x0f0f0f0f)) + ((x >> 4) & (0x0f0f0f0f));
    x = (x & (0x00ff00ff)) + ((x >> 8) & (0x00ff00ff));
    x = (x & (0x0000ffff)) + ((x >> 16) & (0x0000ffff));
    return x;
    /*
	    0x55 = 01010101
		0x33 = 00110011
		0x0f = 00001111
		0xff = 11111111

		It's a divide and conquer approach. 
				Note that the first line will give you the sum on subsequent pairs, 
				next the sum on subsequent quadruples,... and finally the number of bits.

		Example (16 bit so consider your code without the last line)

		1011001111000110
		In the fist line we take & with even bits and odd bits shifted by one. Then we add.

		For even bits:

		num:  10 11 00 11 11 00 01 10
		mask: 01 01 01 01 01 01 01 01
		res:  00 01 00 01 01 00 01 00
		For odd bits:

		num>>1: 01 01 10 01 11 10 00 11
		mask:   01 01 01 01 01 01 01 01
		res:    01 01 00 01 01 00 00 01
		We add those results and get sums in subsequent pairs

		01 10 00 10 10 00 01 01
		We repeat the same with following masks and corresponding shifts

		2nd: 0011 0011 0011 0011
		3rd: 0000 1111 0000 1111
		4th: 0000 0000 1111 1111
		And we get:

		2nd: 0011 0010 0010 0010  // 3 set in the first four, 2 in other quadrupels
		3rd: 0000 0101 0000 0100  // 5 bits set in the first eight, 4 in the rest
		4th: 0000 0000 0000 1001  // 9 bits in total
    */
}


int _64bit_Instruction_for_32_bit(){
	// 0) This method requires a 64-bit CPU with fast modulus division to be efficient. The first option takes only 3 operations; 
	// 		the second option takes 10; and the third option takes 15.
	unsigned int v; // count the number of bits set in v
	unsigned int c; // c accumulates the total bits set in v

	// option 1, for at most 14-bit values in v:
	c = (v * 0x200040008001ULL & 0x111111111111111ULL) % 0xf;

	// option 2, for at most 24-bit values in v:
	c =  ((v & 0xfff) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
	c += (((v & 0xfff000) >> 12) * 0x1001001001001ULL & 0x84210842108421ULL) 
	     % 0x1f;

	// option 3, for at most 32-bit values in v:
	c =  ((v & 0xfff) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
	c += (((v & 0xfff000) >> 12) * 0x1001001001001ULL & 0x84210842108421ULL) % 
	     0x1f;
	c += ((v >> 24) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
	return c;
}

int main(){
	
}