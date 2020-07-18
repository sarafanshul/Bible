// https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/A
// O(Nlog(N))
#include <bits/stdc++.h>
using namespace std;

struct segtree {
	int size;
	vector<long long> sums;
	int _n;

	void init(int n){
		_n = n + 1;
		size = 1;
		while (size < _n) size *= 2;
		sums.assign(2*size , 0LL);
	}

	void set(int i ,int v ,int x ,int lx ,int rx){
		if (rx - lx == 1){
			sums[x] = v;
			return;
		}
		int m = (lx + rx) /2;
		if (i < m) set (i ,v ,2*x + 1 ,lx ,m);
		else set(i ,v ,2*x + 2 ,m ,rx);
		sums[x] = sums[2*x + 1] + sums[2*x + 2];
	}

	void set(int i  ,int v){
		set(i ,v ,0  ,0 ,size);
	}
	
	long long _sum(int l ,int r , int x ,int lx ,int rx){
		if (lx >= r || l >= rx) return 0;
		if (lx >= l && rx <= r) return sums[x];
		int m = (lx + rx)/2; 
		long long s1 = _sum(l ,r ,2*x + 1 ,lx ,m);
		long long s2 = _sum(l ,r ,2*x + 2 ,m ,rx);
		return s1 + s2;
	}

	long long _sum(int l){ // (L ,R] => (inc (L) ,inc(R-1)) 
		return _sum(l ,(_n + 1) ,0 ,0 ,size);
	}

	void print(){
		cout << "\n";
		for (int i : sums) cout << i << " ";
		cout << "\n";
	}
};

int main(){
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	segtree st;
	st.init(n);
	vector<int> a(n);

	for (int  i = 0; i < n; i++) cin >> a[i];
	for (int i : a){
		st.set(i+1 ,1);
		cout << st._sum(i + 2) << " ";
	}

	return 0;
}
