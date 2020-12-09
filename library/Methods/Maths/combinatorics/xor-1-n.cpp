// Given a number n, the task is to find the XOR from 1 to n.
/*
(Efficient method) :
1- Find the remainder of n by moduling it with 4.
2- If rem = 0, then xor will be same as n.
3- If rem = 1, then xor will be 1.
4- If rem = 2, then xor will be n+1.
5- If rem = 3 ,then xor will be 0.
https://www.geeksforgeeks.org/calculate-xor-1-n/
Wht ?
	When we do XOR of numbers, we get 0 as XOR value just before a multiple of 4. This keeps repeating before every multiple of 4
*/

template<typename T = long long>
T computeXOR(const T x){ 
	// Modulus operator are expensive on most of the  
	// computers. n & 3 will be equivalent to n % 4.    
	switch(x & 3){ // n % 4 
		case 0: return x;     // if n is multiple of 4 
		case 1: return 1;     // If n % 4 gives remainder 1   
		case 2: return x + 1; // If n % 4 gives remainder 2     
		case 3: return 0;     // If n % 4 gives remainder 3   
	}
}