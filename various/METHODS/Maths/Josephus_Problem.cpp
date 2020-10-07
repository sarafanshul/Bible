// https://www.youtube.com/watch?v=uCsD3ZGzMgE
// https://www.youtube.com/watch?v=fZ3p2Iw-O2I
// https://cp-algorithms.com/others/josephus_problem.html

#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 1e6 + 7;

template<typename T = long long>
inline T josephus_rec(T n, T k) { // O(N)
	return n > 1 ? (josephus(n-1, k) + k - 1) % n + 1 : 1;
}

template<typename T = long long>
T josephus_iter(T n, T k) { // O(N)
	T res = 0;
	for (T i = 1; i <= n; ++i)
		res = (res + k) % i;
	return res + 1;
}

template<typename T = long long>
T josephus(T n, T k) { // O(K log(N) )
	if (n == 1) return 0;
	if (k == 1) return n-1;
	if (k > n) return (josephus(n-1, k) + k) % n;
	T cnt = n / k;
	T res = josephus(n - cnt, k);
	res -= n % k;
	if (res < 0) res += n;
	else res += res / (k - 1);
	return res;
}

signed main(){
	cout << josephus_rec<long long>(41LL ,2LL)<<'\n';
	cout << josephus_iter<long long>(41LL ,2LL)<<'\n';
	cout << josephus<long long>(41LL ,2LL)<<'\n';
}