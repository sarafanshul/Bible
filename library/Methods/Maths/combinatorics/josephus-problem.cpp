// https://www.youtube.com/watch?v=uCsD3ZGzMgE
// https://www.youtube.com/watch?v=fZ3p2Iw-O2I
// https://cp-algorithms.com/others/josephus_problem.html

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
