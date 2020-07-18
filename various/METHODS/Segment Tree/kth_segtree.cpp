// https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/B
#include <bits/stdc++.h>
using namespace std;

struct segtree {
	int size ,_n;
	vector<long long> sums;

	void init(int n){
		size = 1;
		_n = n;
		while (size < n) size *= 2;
		sums.assign(2*size , 0LL);
	}

	void build(vector<int> &a ,int x ,int lx ,int rx){
		if(rx - lx == 1){
			if (lx < (int)a.size()){
				sums[x] = a[lx];
			}
			return;
		}
		int m = (lx +rx) / 2;
		build(a ,2*x + 1 ,lx ,m);
		build(a ,2*x + 2 ,m ,rx);
		sums[x] = sums[2*x + 1] + sums[2*x + 2];
	}

	void build(vector<int> &a){
		build(a ,0 ,0 ,size);
	}

	void set(int i ,int x ,int lx ,int rx){
		if (rx - lx == 1){
			sums[x] = (sums[x] + 1LL)%2;
			return;
		}
		int m = (lx + rx) /2;
		if (i < m){
			set (i ,2*x + 1 ,lx ,m);
		} else {
			set(i ,2*x + 2 ,m ,rx);
		}
		sums[x] = sums[2*x + 1] + sums[2*x + 2];
	}

	void set(int i){
		set(i ,0 ,0 ,size);
	}

	// long long sum(int l ,int r , int x ,int lx ,int rx){
	// 	// 3 cases
	// 	if (lx >= r || l >= rx) return 0;
	// 	if (lx >= l && rx <= r) return  sums[x];
	// 	int m = (lx + rx)/2;
	// 	long long s1 = sum(l ,r ,2*x + 1 ,lx ,m);
	// 	long long s2 = sum(l ,r ,2*x + 2 ,m ,rx);
	// 	return s1 + s2;  
	// }

	// long long sum(int l ,int r){
	// 	return sum(l ,r ,0 ,0 ,size);
	// }

	long long find(int v ,int x ,int bt){
		if ((v == 0 || v == 1) && (x >= (size - 1))) return x - size + 1;
		if (v + 1 <= sums[2*x + 1]) return find(v ,2*x + 1 ,0); // left
		return find(v - sums[2*x + 1] ,2*x + 2 ,1); // right
	}

	long long find(int v){
		return find(v ,0 ,0);
	}
};

int main(){
	ios::sync_with_stdio(false);

	int n , m ;
	cin  >> n >> m;

	segtree st;
	st.init(n);
	vector<int> a(n);

	for (int  i = 0; i < n; i++) cin >> a[i];

	st.build(a);

	while (m-- ){
		int op;
		cin >> op;
		if (op == 1){
			int i;
			cin >> i;
			st.set(i);
		} else {
			int c;
			cin >> c;
			cout << st.find(c) << "\n";
		}
	}

	return 0;
}