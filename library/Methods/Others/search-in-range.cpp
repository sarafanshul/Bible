vector<long long>v;

// largest element(x) E  l <= x <= r
// search in -> [l ,r] ** SORTED ARRAY 
bool search_rng(long long l ,long long r){
	// sort(ALL(v));
	vector<long long>::iterator iter = lower_bound(v.begin(),v.end(),r+1);
	if (iter != v.begin() && *(--iter) >= l) {
		// printf("%d\n", *iter);
		return 1;
	}
	else{
		// printf("-1\n");
		return 0;
	}
}