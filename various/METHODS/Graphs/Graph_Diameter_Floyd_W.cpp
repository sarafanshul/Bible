// https://codeforces.com/blog/entry/17974
// -> we can define eccentricity of node as maximal distance from that node to other
// https://www.youtube.com/watch?v=2PFl93WM_ao

// pragma for fast runtime optimization
// // #pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

// header(s)
#include <bits/stdc++.h>

// custom aliases
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define MP make_pair
// // for overflow
// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

// namespaces
using namespace std;

// global declerations
const int   N; // Number of nodes in graph
const int   INF = INT_MAX; // Infinity
int         d[N][N]; // Distances between nodes
int         e[N]; // Eccentricity of nodes
set <int>   c; // Center of graph
int         rad = INF; // Radius of graph
int         diam = INT_MIN; // Diamater of graph

// Floyd-Warshall's APSP algorithm
for (int k = 0; k < N; k++) {
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
}

// Counting values of eccentricity
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        e[i] = max(e[i], d[i][j]);
    }
}

for (int i = 0; i < n; i++) {
    rad = min(rad, e[i]);
    diam = max(diam, e[i]);
}

for (int i = 0; i < n; i++) {
    if (e[i] == rad) {
        c.insert(i);
    }
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
	return 0;
}
