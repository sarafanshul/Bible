
void calc(const vector<long long> & v){
	// do work here;
}
void recur(vector<long long> &arr ,vector<long long> &out, long long i, long long k){
	if (k == 0) {calc(out);return;}
	if (i < 0) return;
	out.push_back(arr[i]);
	recur(arr ,out, i - 1, k - 1);
	out.pop_back();		// backtrack
	while (i > 0 && arr[i] == arr[i-1]) i--; // if sorted
	recur(arr ,out, i - 1, k);
}

void combinations(vector<long long> arr){
	vector<long long> temp;
	long long _len = 4;
	recur(arr ,temp ,arr.size() - 1 ,_len);
}