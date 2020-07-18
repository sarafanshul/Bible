// https://codeforces.com/edu/course/2/lesson/4/2

#include <bits/stdc++.h>
using namespace std;

struct segtree {
	int size;
	vector<long long> maxs ,msum ,pref ,sufx;

	void init(int n){
		size = 1;
		while (size < n) size *= 2;
		maxs.assign(2*size , 0);
		msum.assign(2*size , 0);
		pref.assign(2*size , 0);
		sufx.assign(2*size , 0);
	}


	void build(vector<int> &a ,int x ,int lx ,int rx){
		if(rx - lx == 1){
			if (lx < (int)a.size()){ 
				maxs[x] = a[lx];
				msum[x] = a[lx];
				pref[x] = a[lx];
				sufx[x] = a[lx];
			}
			return;
		}
		int m = (lx +rx) / 2;
		build(a ,2*x + 1 ,lx ,m);
		build(a ,2*x + 2 ,m ,rx);
		pref[x] = max(pref[2*x + 1] ,(msum[2*x + 1] + pref[2*x + 2]) );
		sufx[x] = max(sufx[2*x + 2] ,(msum[2*x + 2] + sufx[2*x + 1]) );
		msum[x] = msum[2*x + 1] + msum[2*x + 2];
		maxs[x] = max( max(maxs[2*x + 1] ,maxs[2*x + 2]) ,(sufx[2*x + 1] + pref[2*x + 2]));
		// maxs[x] = max_seg(maxs[2*x + 1] , maxs[2*x + 2]);
	}

	void build(vector<int> &a){
		build(a ,0 ,0 ,size);
	}

	void set(int i ,int v ,int x ,int lx ,int rx){
		if (rx - lx == 1){
			maxs[x] = v;
			msum[x] = v;
			pref[x] = v;
			sufx[x] = v;
			return;
		}
		int m = (lx + rx) /2;
		if (i < m) set (i ,v ,2*x + 1 ,lx ,m);
		else set(i ,v ,2*x + 2 ,m ,rx);
		pref[x] = max(pref[2*x + 1] ,(msum[2*x + 1] + pref[2*x + 2]) );
		sufx[x] = max(sufx[2*x + 2] ,(msum[2*x + 2] + sufx[2*x + 1]) );
		msum[x] = msum[2*x + 1] + msum[2*x + 2];
		maxs[x] = max( max(maxs[2*x + 1] ,maxs[2*x + 2]) ,(sufx[2*x + 1] + pref[2*x + 2]));
		// maxs[x] = max_seg(maxs[2*x + 1] , maxs[2*x + 2] );
	}

	void set(int i  ,int v){
		set(i ,v ,0  ,0 ,size);
	}

	// NOT WORKING AND NOT NEEDED :))   (.)(.)
	// long long _max(int l ,int r , int x ,int lx ,int rx){
	// 	// 3 cases
	// 	if (lx >= r || l >= rx) return 0; // 1) out of all ranges
	// 	if (lx >= l && rx <= r) return maxs[x]; // 2) contain full ranges
	// 	int m = (lx + rx)/2; // 3 ) partial;
	// 	long long s1 = _max(l ,r ,2*x + 1 ,lx ,m);
	// 	long long s2 = _max(l ,r ,2*x + 2 ,m ,rx);
	//	// return s1 + s2;
	// 	// return max_seg(s1 , s2);  
	// }

	// long long _max(int l ,int r){
	// 	return _max(l ,r ,0 ,0 ,size);
	// }

	void print_tree(){
		cout << "\n";
		cout << "MAXS" << " -> ";
		for(int i = 0; i < size*2 ;++i){
			cout << maxs[i] << " - ";
		}
		cout << "\n";
		cout << "MSUM" << " -> ";
		for(int i = 0; i < size*2 ;++i){
			cout << msum[i] << " - ";
		}
		cout << "\n";
		cout << "PREF" << " -> ";
		for(int i = 0; i < size*2 ;++i){
			cout << pref[i] << " - ";
		}
		cout << "\n";
		cout << "SUFX" << " -> ";
		for(int i = 0; i < size*2 ;++i){
			cout << sufx[i] << " - ";
		}
		cout << "\n";
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
	// st.print_tree();
	// cout << max(st._max(0 ,n) ,0LL) << "\n";
	cout << max(st.maxs[0] ,0LL) << "\n";
	while ( m-- ){
		cin >> x >> y;
		st.set(x ,y);
		// st.print_tree();
		cout << max(st.maxs[0] ,0LL) << "\n";
	}

	return 0;
}