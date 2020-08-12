

#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define int long long

using namespace std;

const uint32_t MOD = 1e9+7;
const uint32_t MAXN = 1e6+7;
int n;

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

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    return 0;
}