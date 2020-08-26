// trajan's Algorithm for scc
// https://www.youtube.com/watch?v=cY4HiiFHO1o&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=24
// https://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/
// 
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
// #define int long long
#define MP make_pair

using namespace std;
const size_t MAXN = 1e5 +7;

vector<vector<int>> adj(MAXN ,vector<int>(0));
vector<int> disc(MAXN ,-1) ,low(MAXN ,-1) ,component;
bool onstack[MAXN] = {0};
stack<int> st;
int n ,m ,sccCount = 0;

void print_components(){
	for(size_t i = 0; i < component.size(); i++){
		cout << component[i] << " ";
	}cout << "\n";
}

void SCCUtil(int u){
	static int time = 0;
	disc[u] = low[u] = ++time;
	st.push(u);
	onstack[u] = 1;

	for(int v : adj[u]){
		if(disc[v] == -1){
			SCCUtil(v);
			low[u] = min(low[u] ,low[v]);
		}
		else if(onstack[v] == true){
			low[u] = min(low[u] ,disc[v]);
		}
	}
	int w = 0;
	if(low[u] == disc[u]){
	    sccCount++;
		while(st.top() != u){
			w = st.top(); st.pop();
			onstack[w] = 0;
			component.PB(w);
		}
		w = st.top(); st.pop();
		onstack[w] = 0;
		component.PB(w);
		//
		print_components();
	    component.clear();
	}
}

void findSCC(){
	for(int i = 0; i < n ; i++){
		if(disc[i] == -1) SCCUtil(i);
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	component.reserve(MAXN);
	int a, b;
	cin >> n;
	cin >> m;
	for (int i = 0; i< m ;i++) {
		cin >> a >> b;
		adj[a].push_back (b);
	}
	findSCC();
	cout << sccCount;
	return 0;
}
