//Derangement Generation of an Array
//Definition: Derangement of a permutation is another ordering where each and every element of the permutation is not in its original position.
//https://codeforces.com/blog/entry/66176
//https://www.codechef.com/problems/MARCAPS
vector<ll> gen(vector<ll> &a){
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
