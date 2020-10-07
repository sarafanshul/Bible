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
