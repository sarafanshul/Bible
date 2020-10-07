/*
Every even integer greater than 2 is the sum of two primes.

*/
#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 1e6 + 7;

vector<bool> is_prime(MAXN+1, true);
vector<long long> primes;
void pre(){	
	primes.reserve(MAXN);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= MAXN; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= MAXN; j += i)
				is_prime[j] = false;
		}
	}
	for(int i = 0 ;i < MAXN ;i++){
		if(is_prime[i]) primes.push_back(i);
	}
}

template<typename T = long long>
T goldbach_C(T n){
	T count = 0;
	for(size_t i = 0 ;i < primes.size() ;i++){
		if(n <= primes[i]) break;
		if(is_prime[n-primes[i]]) {
			cout << n <<" "<< n-primes[i]<<"\n" ,count++;
		}
	}
	return count;
}

signed main(){
	pre();
	goldbach_C<long long>(324LL);
}