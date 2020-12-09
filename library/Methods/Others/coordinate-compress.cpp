// coordinate compression
// Coordinate Compression is mainly used to map larger 
//  values to smaller values to remove the vacant space
// https://codeforces.com/blog/entry/84164
map<long long, long long> M;
vector<long long> b;
void compress(vector<long long> &a){
	b = a;
	sort(b.begin(), b.end());
	for(int i = 0 ;i < b.size() ;i++){ M[b[i]] = i; }
	for(int i = 0 ; i < b.size() ;i++){ a[i] = M[a[i]]; }
}
