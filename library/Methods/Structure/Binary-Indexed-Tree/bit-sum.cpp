//  -== BIT ==
//
// ===== 0 BASED - INDEXING ====
//
//
//  === resources ===
// https://www.youtube.com/watch?v=kPaJfAUwViY
// https://www.topcoder.com/community/competitive-programming/tutorials/binary-indexed-trees/
// https://cp-algorithms.com/data_structures/fenwick.html
//

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            _add(i, a[i]);
    }

    int _sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int _sum(int l, int r) {
        return _sum(r) - _sum(l - 1);
    }

    void _add(int idx, int delta) {
        // cout <<"idx->"<<idx<<  " d->"<<delta<<" -- ";
        for (; idx < n; idx = idx | (idx + 1))
			bit[idx] += delta;
		
// 		for(size_t i = 0; i < bit.size(); i++ ) cout<<  bit[i] << " ";
//         cout << "\n";
    }   
    
};


int32_t main(){

	int n ,q ,x ,y ,z;
	cin >> n >> q;
	vector<int> a(n);
	for(size_t i = 0 ;i < n ;i++) cin >> a[i];
	
	FenwickTree ft(a);

	while(q--){
	   // cout << "--\n";
		cin >> x >> y >> z;
		if(x == 1) {
		    ft._add(y ,z - a[y]);
		    a[y] = z; // forgot to update a LOL
		}
		else cout << ft._sum(y ,z-1) << "\n";
	}

	return 0;
}
