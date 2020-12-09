int dp[MAXN];
inline int mod(int a ,int b){return (a+b >= MOD)?(a+b-MOD):(a+b);}
uint32_t kadane(vector<int> &array){
	int best = 0, sum = 0;
	for (int k = 0; k < n; k++) {
		sum = max(array[k],sum+array[k]);
		best = max(best,sum);
	}
	return best;
}
