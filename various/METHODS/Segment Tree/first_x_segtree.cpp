//https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/D

#include <bits/stdc++.h>
using namespace std;

struct segtree {
	int size;
	vector<long long> maxs;

	void init(int n){
		size = 1;
		while (size < n) size *= 2;
		maxs.assign(2*size , 0LL);
	}

	void build(vector<int> &a ,int x ,int lx ,int rx){
		if(rx - lx == 1){
			if (lx < (int)a.size()) maxs[x] = a[lx];
			return;
		}
		int m = (lx +rx) / 2;
		build(a ,2*x + 1 ,lx ,m);
		build(a ,2*x + 2 ,m ,rx);
		maxs[x] = max(maxs[2*x + 1] , maxs[2*x + 2]);
	}

	void build(vector<int> &a){
		build(a ,0 ,0 ,size);
	}

	void set(int i ,int v ,int x ,int lx ,int rx){
		if (rx - lx == 1){
			maxs[x] = v;
			return;
		}
		int m = (lx + rx) /2;
		if (i < m) set (i ,v ,2*x + 1 ,lx ,m);
		else set(i ,v ,2*x + 2 ,m ,rx);
		maxs[x] = max(maxs[2*x + 1] , maxs[2*x + 2]);
	}

	void set(int i  ,int v){
		set(i ,v ,0  ,0 ,size);
	}

	long long _max(int v ,int x){
		if ((x >= (size - 1)) && (v > maxs[x])) return -1;
		if (v <= maxs[x] && (x >= (size - 1))) return x - size + 1;
		if (v <= maxs[2*x + 1]) return _max(v ,2*x + 1);
		return _max(v ,2*x + 2);
	}

	long long _max(int x){
		return _max(x ,0);
	}

	bool check_r(int x ,int l){
		if (x >= (size - 1)){
			if ((x - size + 1) >= l) return true;
			else return false;
		}
		return check_r(2*x + 2 ,l);
	}

	long long find_above(int v ,int l ,int x ,int lx ,int rx){
		if (maxs[x] < v) return -1;
		if (rx <= l) return -1; // check condition for { L } 
		if (rx - lx == 1) return lx;
		int m = (lx + rx) / 2;
		int res = find_above(v ,l ,2*x + 1 ,lx ,m);
		if (res == -1){
			res = find_above(v ,l ,2*x + 2 ,m ,rx);
		}
		return res;	
	}

	long long find_above(int v ,int l){
		return find_above(v ,l ,0 ,0 ,size);
	}
};

int main(){
	ios::sync_with_stdio(false);

	int n , m , op ,x ,y;
	cin  >> n >> m;

	segtree st;
	st.init(n);
	vector<int> a(n);

	for (int  i = 0; i < n; i++) cin >> a[i];

	st.build(a);
	
	while ( m-- ){
		cin >> op;
		cin >> x >> y;
		if (op == 1) st.set(x ,y);
		else cout << st.find_above(x ,y) << "\n";
	}

	return 0;
}
