#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 1e6 + 7;

template<long long SZ> struct Sieve {
	bitset<SZ> pri;
	vector<long long> pr;
	Sieve() {
		pri.set();
		pri[0] = pri[1] = 0;
		for (int i = 4; i < SZ; i += 2) {
			pri[i] = 0;
		}
		for (int i = 3; i * i < SZ; i += 2) {
			if (pri[i]) {
				for (int j = i * i; j < SZ; j += 2 * i) {
					pri[j] = 0;
				}
			}
		}
		for (int i = 0; i < SZ; i++) {
			if (pri[i]) {
				pr.push_back(i);
			}
		}
	}
};

int main(){
	Sieve<MAXN> S;
	S.pri[10];
	S.pr[11];
}
