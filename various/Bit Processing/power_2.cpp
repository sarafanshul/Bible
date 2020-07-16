#include<bits/stdc++.h>

using namespace std;

int main(){
	unsigned int v; // we want to see if v is a power of 2
	bool f;         // the result goes here 

	f = (v & (v - 1)) == 0; 
	// eg (8)=>[(1000)&(0111)] == 0
	// Note that 0 is incorrectly considered a power of 2 here. To remedy this, use:
	f = v && !(v & (v - 1)); // using boolean and operator we elimenate 0;
	return 0;
}