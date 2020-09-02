
// https://codeforces.com/blog/entry/17974
// https://www.youtube.com/watch?v=2PFl93WM_ao
// -> we can define eccentricity of node as maximal distance from that node to other
// 

/*
Possible algorithm for finding center of tree is the following: 
    using BFS from any node (denote it as v1) 
    find the farthest from v1 node (denote as v2), then run BFS from v2, 
    choose the farthest node from v2 (call it v3). 
    Nodes in the middle of the path between v2 and v3 are center of graph, 
    distance between them is diameter. Radius of graph is
    half of diameter rounded up: (diam(G) + 1) / 2. 

Theorem: Let L be set of leaves of G. If |V| ≤ 2 then L is center of G, 
otherwice center of graph remains the same after removing of L:


This theorem brings us to the following algorithm: 
    remove leaves, level by level, until there are  ≤ 2 nodes. 
    These nodes will be center of graph. 
    
Implementation of this algorithm is similar to BFS:
*/

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

const int   N = ...; // Number of nodes in graph
int         maxlevel = 0; // Level of center of graph
int         level[N]; // Level of node
int         degree[N]; // Degree of node
int         g[N][N]; // Adjacency matrix
set <int>   c; // Center of graph
queue <int> q; // Queue for algo

// Start from leaves
for (int i = 0; i < N; i++) {
    if (degree[i] == 1) {
        q.push(i);
    }
}

while (!q.empty()) {
    int v = q.front();
    q.pop();

    // Remove leaf and try to add its parent
    for (int i = 0; i < N; i++) {
        if (g[v][i]) {
            degree[i]--;
            
            if (degree[i] == 1) {
                q.push(i);
                level[i] = level[v] + 1;
                maxlevel = max(maxlevel, level[i]);
            }
        }
    }
}

for (int i = 0; i < N; i++) {
    if (level[i] == maxlevel) {
        c.insert(i);
    }
}

// It's not so hard to prove that after running of this algo 
// center of graph will be in c,  и rad(G) = (diam(G) + 1) / 2.

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    cin.exceptions(cin.failbit);
    return 0;
}