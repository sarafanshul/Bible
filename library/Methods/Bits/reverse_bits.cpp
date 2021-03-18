
// http://graphics.stanford.edu/~seander/bithacks.html
//Reverse bits in word by lookup table
static const unsigned char BitReverseTable256[256] = 
{
#   define R2(n)     n,     n + 2*64,     n + 1*64,     n + 3*64
#   define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16)
#   define R6(n) R4(n), R4(n + 2*4 ), R4(n + 1*4 ), R4(n + 3*4 )
    R6(0), R6(2), R6(1), R6(3)
};

uint32_t reverse_lookup(){
	unsigned int v; // reverse 32-bit value, 8 bits at time
	unsigned int c; // c will get v reversed

	// Option 1:
	c = (BitReverseTable256[v & 0xff] << 24) | 
	    (BitReverseTable256[(v >> 8) & 0xff] << 16) | 
	    (BitReverseTable256[(v >> 16) & 0xff] << 8) |
	    (BitReverseTable256[(v >> 24) & 0xff]);

	// Option 2:
	unsigned char * p = (unsigned char *) &v;
	unsigned char * q = (unsigned char *) &c;
	q[3] = BitReverseTable256[p[0]]; 
	q[2] = BitReverseTable256[p[1]]; 
	q[1] = BitReverseTable256[p[2]]; 
	q[0] = BitReverseTable256[p[3]];
	// The first method takes about 17 operations, 
	// and the second takes about 12, assuming your CPU can load and store bytes easily.
}

uint reverse_64_bit_multi_mod(){
	unsigned char b; // reverse this (8-bit) byte
	b = (b * 0x0202020202ULL & 0x010884422010ULL) % 1023;
}

uint reverse_parallel(){
	unsigned int v; // 32-bit word to reverse bit order

	// swap odd and even bits
	v = ((v >> 1) & 0x55555555) | ((v & 0x55555555) << 1);
	// swap consecutive pairs
	v = ((v >> 2) & 0x33333333) | ((v & 0x33333333) << 2);
	// swap nibbles ... 
	v = ((v >> 4) & 0x0F0F0F0F) | ((v & 0x0F0F0F0F) << 4);
	// swap bytes
	v = ((v >> 8) & 0x00FF00FF) | ((v & 0x00FF00FF) << 8);
	// swap 2-byte long pairs
	v = ( v >> 16             ) | ( v               << 16);

	// The following variation is also O(lg(N)), however it requires more operations to reverse v. Its virtue is in taking less slightly memory by computing the constants on the fly.
	unsigned int s = sizeof(v) * CHAR_BIT; // bit size; must be power of 2 
	unsigned int mask = ~0;         
	while ((s >>= 1) > 0) {
	  mask ^= (mask << s);
	  v = ((v >> s) & mask) | ((v << s) & ~mask);
	}
}

int main(){
	//Reverse bits the obvious way
	unsigned int v;     // input bits to be reversed
	unsigned int r = v; // r will be reversed bits of v; first get LSB of v
	int s = sizeof(v) * CHAR_BIT - 1; // extra shift needed at end

	for (v >>= 1; v; v >>= 1){   
	  r <<= 1;
	  r |= v & 1;
	  s--;
	}
	r <<= s; // shift when v's highest bits are zero

}