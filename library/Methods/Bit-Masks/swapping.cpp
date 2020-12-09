// http://graphics.stanford.edu/~seander/bithacks.html
#include <bits/stdc++.h>
// XOR Swap 
#define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))
/*
Fleming pointed out that the macro above doesn't work when 
you swap with the same memory location, 
such as SWAP(a[i], a[j]) with i == j. 
So if that may occur, consider defining the macro as 
	(((a) == (b)) || (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))). 
On July 14, 2009, Hallvard Furuseth suggested that on some machines, 
	(((a) ^ (b)) && ((b) ^= (a) ^= (b), (a) ^= (b))) 
might be faster, since the (a) ^ (b) expression is reused.

*/
using namespace std;

void swap_bits(){
	unsigned int i, j; // positions of bit sequences to swap
	unsigned int n;    // number of consecutive bits in each sequence
	unsigned int b;    // bits to swap reside in b
	unsigned int r;    // bit-swapped result goes here

	unsigned int x = ((b >> i) ^ (b >> j)) & ((1U << n) - 1); // XOR temporary
	r = b ^ ((x << i) | (x << j));
	// As an example of swapping ranges of bits suppose we have have b = 00101111 (expressed in binary) and we want to swap the n = 3 consecutive bits starting at i = 1 (the second bit from the right) with the 3 consecutive bits starting at j = 5; the result would be r = 11100011 (binary).
	// This method of swapping is similar to the general purpose XOR swap trick, but intended for operating on individual bits.  The variable x stores the result of XORing the pairs of bit values we want to swap, and then the bits are set to the result of themselves XORed with x.  
	// Of course, the result is undefined if the sequences overlap.
}

int main(){

}