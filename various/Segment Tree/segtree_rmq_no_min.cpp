// following is done using building 2 segment trees  ,but can be optimizet to a single tree
// for less memory&time complexicity

#include <bits/stdc++.h>
using namespace std;

struct segtree {
	int size;
	vector<int> mins;
	vector<pair<int ,int>> min_seg;

	void init(int n){
		size = 1;
		while (size < n) size *= 2;
		mins.assign(2*size , INT_MAX);
		min_seg.assign(2*size , make_pair(INT_MAX ,0LL)); //[val ,times]
	}

	int min(int a ,int b){
		return (a < b) ? a : b;
	}

	void build(vector<int> &a ,int x ,int lx ,int rx){
		if(rx - lx == 1){
			if (lx < (int)a.size()) mins[x] = a[lx];
			return;
		}
		int m = (lx +rx) / 2;
		build(a ,2*x + 1 ,lx ,m);
		build(a ,2*x + 2 ,m ,rx);
		mins[x] = min(mins[2*x + 1] , mins[2*x + 2]);
	}

	void build(vector<int> &a){
		build(a ,0 ,0 ,size);
	}

	void build_m(vector<int> &a ,int x ,int lx ,int rx){
		if(rx - lx == 1){
			if (lx < (int)a.size()) min_seg[x] = make_pair(a[lx] ,1);
			return;
		}
		int m = (lx +rx) / 2;
		build_m(a ,2*x + 1 ,lx ,m);
		build_m(a ,2*x + 2 ,m ,rx);

		if (min_seg[2*x + 1].first == min_seg[2*x + 2].first){
			min_seg[x] = make_pair(min_seg[2*x + 1].first ,(min_seg[2*x + 1].second + min_seg[2*x + 2].second));
		} else if (min_seg[2*x + 1].first < min_seg[2*x + 2].first){
			min_seg[x] = min_seg[2*x + 1];
		} else{
			min_seg[x] = min_seg[2*x + 2];
		}
	}

	void build_m(vector<int> &a){
		build_m(a ,0 ,0 ,size);
	}

	void set(int i ,int v ,int x ,int lx ,int rx){
		if (rx - lx == 1){
			mins[x] = v;
			return;
		}
		int m = (lx + rx) /2;
		if (i < m) set (i ,v ,2*x + 1 ,lx ,m);
		else set(i ,v ,2*x + 2 ,m ,rx);
		mins[x] = min(mins[2*x + 1] , mins[2*x + 2]);
	}

	void set(int i  ,int v){
		set(i ,v ,0  ,0 ,size);
	}

	void set_m(int i ,int v ,int x ,int lx ,int rx){
		// cout <<"s";
		if (rx - lx == 1){
			min_seg[x] = make_pair(v ,1);
			return;
		}
		int m = (lx + rx) /2;
		if (i < m) set_m(i ,v ,2*x + 1 ,lx ,m);
		else set_m(i ,v ,2*x + 2 ,m ,rx);

		if (min_seg[2*x + 1].first == min_seg[2*x + 2].first){
			min_seg[x] = make_pair(min_seg[2*x + 1].first ,(min_seg[2*x + 1].second + min_seg[2*x + 2].second));
		} else if (min_seg[2*x + 1].first < min_seg[2*x + 2].first){
			min_seg[x] = min_seg[2*x + 1];
		} else min_seg[x] = min_seg[2*x + 2];
		
	}

	void set_m(int i , int v){
		set_m(i ,v ,0 ,0 ,size);
	}

	int _min(int l ,int r , int x ,int lx ,int rx){
		// 3 cases
		if (lx >= r || l >= rx) return INT_MAX; // 1) out of all ranges
		if (lx >= l && rx <= r) return mins[x]; // 2) contain full ranges
		int m = (lx + rx)/2; // 3 ) partial;
		int s1 = _min(l ,r ,2*x + 1 ,lx ,m);
		int s2 = _min(l ,r ,2*x + 2 ,m ,rx);
		return min(s1 ,s2);  
	}

	int _min(int l ,int r){
		return _min(l ,r ,0 ,0 ,size);
	}

	pair<int ,int> no_mins(int l ,int r , int x ,int lx ,int rx){
		// 3 cases
		if (lx >= r || l >= rx) return make_pair(INT_MAX ,0); // 1) out of all ranges
		if (lx >= l && rx <= r) return min_seg[x]; // 2) contain full ranges
		int m = (lx + rx)/2; // 3 ) partial;
		pair<int ,int> s1 = no_mins(l ,r ,2*x + 1 ,lx ,m);
		pair<int ,int> s2 = no_mins(l ,r ,2*x + 2 ,m ,rx);
		if (s1.first == s2.first) return make_pair(s1.first ,s1.second + s2.second);
		else if (s1.first < s2.first) return s1;
		return s2;
	}

	int no_mins(int l ,int r){
		return no_mins(l ,r ,0 ,0 ,size).second;
	}

	void print_trees(){
		for(int i = 0; i< 2*size; ++i){
			if (mins[i] == INT_MAX) cout << "_" << " ";
			else cout << mins[i] << " ";
		}
		cout << "\n\n";
		for (int i = 0; i < 2*size; ++i){
			if (min_seg[i].first == INT_MAX) cout <<" [ _ , _ ] ";
			else cout << " [ " << min_seg[i].first << " , " << min_seg[i].second << " ] ";
		}
		cout <<"\n";
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
	st.build_m(a);
	// st.print_trees();
	
	while ( m-- ){
		cin >> op;
		cin >> x >> y;
		if (op == 1){ 
			st.set(x ,y);
			st.set_m(x ,y);
			// st.print_trees();
		}
		else cout << st._min(x ,y) << " " << st.no_mins(x ,y)<< "\n";
	}

	return 0;
}
