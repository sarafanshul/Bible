ll kadane(vector<ll> &a){
	ll best = -1e18, sum = 0;
	for (ll k = 0; k < a.size(); k++) {
		sum = max(a[k],sum+a[k]);
		best = max(best,sum);
	}
	return best;
}
