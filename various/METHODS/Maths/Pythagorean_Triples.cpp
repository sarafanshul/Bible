/*
resources 
	https://codeforces.com/blog/entry/46681
	https://www.friesian.com/pythag.htm

First, 
 suppose n is the shortest side of the triangle, 
 m, k are other two sides. 
 According to Pythagorean Theorem, 
 we know n^2 + m^2 = k^2

just do a change k^2 - m^2 = n^2

futherly (k + m)(k - m) = n^2

as we know, n^2 × 1 = n^2 =>so we can suppose that 
	-> k + m = n^2, 
	-> k - m = 1 

easily, we get 
-> k = (n^2 + 1)/2
-> m = (n^2 - 1)/2

** because the side is a interger, 
   so this solution can only be used when n is a odd.**

So how to deal with even? we find that if (k-m) is odd, 
the solution is suitable for odd. 
On the other hand, we guess that if(k-m) is even, 
the solution is suitable for even.
just as this, 
-> k + m = (1/2)n^2
-> k - m = 2
so, we get 
-> k = (1/4)n^2 + 1
-> m = k - 2
this is an O(1) algorithm.

*/

#include <bits/stdc++.h>
using namespace std;

template<typename T = long long>
void gen(T n){
	if(n < 3) {cout <<"-1";return;}
	T a ,b ,c;
	if(n%2){
		a = (n*n - 1)/2;
		b = n;
		c = (n*n + 1)/2;
	}else {
		a = (n*n/4)-1;
		b = n;
		c = (n*n/4)+1;
	}
	cout << a << " " << b << " " << c << "\n";
}
int main(){
	long long b = 3;
	gen<long long>(b);
}