//https://codeforces.com/blog/entry/11080
//
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;

// The tree-based container has the following declaration:
template<
	typename Key, // Key type
	typename Mapped, // Mapped-policy
	typename Cmp_Fn = std::less<Key>, // Key comparison functor
	typename Tag = rb_tree_tag, // Specifies which underlying data structure to use
	template<
		typename Const_Node_Iterator,
		typename Node_Iterator,
		typename Cmp_Fn_,
		typename Allocator_>
	class Node_Update = null_node_update, // A policy for updating node invariants
	typename Allocator = std::allocator<char> > // An allocator type
	class tree;

// example 1
typedef tree<
	long long, // Key type
	null_type, // Mapped-policy
	less<long long>, // Key comparison functor
	rb_tree_tag, // Specifies which underlying data structure to use
	tree_order_statistics_node_update> // A policy for updating node invariants
ordered_set;
//
// example 2
typedef tree<
	pair<int,int>,
	null_type,
	less<pair<int,int>>,
	rb_tree_tag,
	tree_order_statistics_node_update>
ordered_set;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int sz=0;
    cin>>n;
    vector<int> ans(n,0);
 
    ordered_set t;
    int x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        ans[t.order_of_key({x,++sz})]++;
        t.insert({x,sz});
    }
 
    for(int i=0;i<n;i++)
        cout<<ans[i]<<'\n';
}
