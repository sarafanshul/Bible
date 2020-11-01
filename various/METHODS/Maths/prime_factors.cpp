// Prime factorizes n in worst case O(sqrt n).
vector<pair<long long, long long>> prime_factorize(long long n) {
	assert(n >= 1);
	vector<pair<long long, long long>> result;
 
	for (long long p = 2; p * p <= n; p++)
		if (n % p == 0) {
			result.emplace_back(p, 0);
 
			do {
				n /= p;
				result.back().second++;
			} while (n % p == 0);
		}
 
	if (n > 1)
		result.emplace_back(n, 1);
 
	return result;
}

long long get_multiplicity(long long n, long long p) {
    long long m = 0;
 
    while (n % p == 0) {
        m++;
        n /= p;
    }
 
    return m;
}