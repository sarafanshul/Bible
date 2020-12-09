template<typename T = long long >
T fastExpo(T a, T n, T MOD) {
	T ans = 1;
	while(n >= 1) {
		if(n % 2 == 0) { a = (1LL * a * a) % MOD; n /= 2; }
		else { ans = (1LL * ans * a) % MOD; n--; }
	}
	return ans;
}