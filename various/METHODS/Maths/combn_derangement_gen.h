//Derangement Generation of an Array
//Definition: Derangement of a permutation is another ordering where each and every element of the permutation is not in its original position.
//https://codeforces.com/blog/entry/66176
//https://www.codechef.com/problems/MARCAPS
////  hash for ll <>
struct custom_hash_ll {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

vector<ll> gen(vector<ll> &a){
#ifndef ll
#define ll long long
#endif
	ll n = a.size();
	vector<pair<ll, ll>> v(n);
	for (int i = 0; i < n; ++i) {
		v[i].first = a[i];
		v[i].second = i;
	}
	sort(v.begin(), v.end());
	gp_hash_table<ll , ll ,custom_hash> mp;
	ll mx = 0;
	for (auto x: v)mp[x.first]++, mx = max(mx, mp[x.first]);
	if (mx > n / 2){return {} ;}

	vector<ll> val, ans(n);
	val.reserve(n*2);
	for (auto x: v)val.push_back(x.first);
	rotate(val.begin(), val.begin() + (ll) val.size() - mx, val.end());
	for (ll i = 0; i < n; i++)ans[v[i].second] = val[i];
	return ans;
}
