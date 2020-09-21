// https://www.geeksforgeeks.org/euler-tour-subtree-sum-using-segment-tree/

// C++ program for implementation of 
// Euler Tour | Subtree Sum. 
#include <bits/stdc++.h> 
using namespace std; 
  
vector<int> v[1001]; 
vector<int> s; 
int seg[1001] = { 0 }; 
  
// Value/Weight of each node of tree, 
// value of 0th(no such node) node is 0. 
int ar[] = { 0, 1, 2, 3, 4, 5, 6 }; 
  
int vertices = 6; 
int edges = 5; 
  
// A recursive function that constructs 
// Segment Tree for array ar[] = { }. 
// 'pos' is index of current node 
// in segment tree seg[]. 
int segment(int low, int high, int pos) 
{ 
    if (high == low) { 
        seg[pos] = ar[s[low]]; 
    } 
    else { 
        int mid = (low + high) / 2; 
        segment(low, mid, 2 * pos); 
        segment(mid + 1, high, 2 * pos + 1); 
        seg[pos] = seg[2 * pos] + seg[2 * pos + 1]; 
    } 
} 
  
/* Return sum of elements in range 
   from index l to r . It uses the  
   seg[] array created using segment() 
   function. 'pos' is index of current 
   node in segment tree seg[]. 
*/
int query(int node, int start, 
          int end, int l, int r) 
{ 
    if (r < start || end < l) { 
        return 0; 
    } 
  
    if (l <= start && end <= r) { 
        return seg[node]; 
    } 
  
    int mid = (start + end) / 2; 
    int p1 = query(2 * node, start, 
                   mid, l, r); 
    int p2 = query(2 * node + 1, mid + 1, 
                   end, l, r); 
  
    return (p1 + p2); 
} 
  
/* A recursive function to update the 
   nodes which have the given index in 
   their range. The following are 
   parameters pos --> index of current  
   node in segment tree seg[]. idx --> 
   index of the element to be updated. 
   This index is in input array.  
   val --> Value to be change at node idx 
*/
int update(int pos, int low, int high, 
           int idx, int val) 
{ 
    if (low == high) { 
        seg[pos] = val; 
    } 
    else { 
        int mid = (low + high) / 2; 
  
        if (low <= idx && idx <= mid) { 
            update(2 * pos, low, mid, 
                   idx, val); 
        } 
        else { 
            update(2 * pos + 1, mid + 1, 
                   high, idx, val); 
        } 
  
        seg[pos] = seg[2 * pos] + seg[2 * pos + 1]; 
    } 
} 
  
/* A recursive function to form array 
    ar[] from a directed tree . 
*/
int dfs(int root) 
{ 
    // pushing each node in vector s 
    s.push_back(root); 
    if (v[root].size() == 0) 
        return root; 
  
    for (int i = 0; i < v[root].size(); i++) { 
        int temp = dfs(v[root][i]); 
        s.push_back(temp); 
    } 
    return root; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Edges between the nodes 
    v[1].push_back(2); 
    v[1].push_back(3); 
    v[2].push_back(6); 
    v[2].push_back(5); 
    v[3].push_back(4); 
  
    // Calling dfs function. 
    int temp = dfs(1); 
    s.push_back(temp); 
  
    // Storing entry time and exit 
    // time of each node 
    vector<pair<int, int> > p; 
  
    for (int i = 0; i <= vertices; i++) 
        p.push_back(make_pair(0, 0)); 
  
    for (int i = 0; i < s.size(); i++) { 
        if (p[s[i]].first == 0) 
            p[s[i]].first = i + 1; 
        else
            p[s[i]].second = i + 1; 
    } 
  
    // Build segment tree from array ar[]. 
    segment(0, s.size() - 1, 1); 
  
    // query of type 1 return the 
    // sum of subtree at node 1. 
    int node = 1; 
    int e = p[node].first; 
    int f = p[node].second; 
  
    int ans = query(1, 1, s.size(), e, f); 
  
    // print the sum of subtree 
    cout << "Subtree sum of node " << node << " is : " << (ans / 2) << endl; 
  
    // query of type 2 return update 
    // the subtree at node 6. 
    int val = 10; 
    node = 6; 
  
    e = p[node].first; 
    f = p[node].second; 
    update(1, 1, s.size(), e, val); 
    update(1, 1, s.size(), f, val); 
  
    // query of type 1 return the 
    // sum of subtree at node 2. 
    node = 2; 
  
    e = p[node].first; 
    f = p[node].second; 
  
    ans = query(1, 1, s.size(), e, f); 
  
    // print the sum of subtree 
    cout << "Subtree sum of node " << node << " is : " << (ans / 2) << endl; 
  
    return 0; 
} 
