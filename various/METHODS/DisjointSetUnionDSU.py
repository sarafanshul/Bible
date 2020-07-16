'''
Disjoint Set (Or Union-Find)
	A disjoint-set data structure is a 
	data structure that keeps track of 
	a set of elements partitioned into 
	a number of disjoint (non-overlapping) 
	subsets. A union-find algorithm is an 
	algorithm that performs two useful 
	operations on such a data structure:


	Find: Determine which subset a 
		particular element is in. This 
		can be used for determining if 
		two elements are in the same subset.

	Union: Join two subsets into a single subset.

brief = >
	If a group of characters is interconnected by
	swap pairs, you can freely rearrange characters 
	within that group.

	In this example, we have two group of 
	interconnected characters, so we can make 
	rearrangements to achieve the smallest string 

example = https://leetcode.com/problems/smallest-string-with-swaps/

HOW ?
Identify groups using union-find. 
For each group, collect all its characters in a string.

Note that in the disjoined set ds, the find operation
 returns the parent index (p). We use that index to 
 identify the group, and put all group characters into m[p].

Sort the string, then put the rearranged 
characters back to their respective positions in the group.

'''
## c++ code

int find(vector<int>& ds, int i) {
  return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
}
string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
  vector<int> ds(s.size(), -1);
  vector<vector<int>> m(s.size());
  for (auto& p : pairs) {
	auto i = find(ds, p[0]), j = find(ds, p[1]);
	if (i != j) ds[j] = i;
  }
  for (auto i = 0; i < s.size(); ++i) m[find(ds, i)].push_back(i);
  for (auto ids : m) {
	string ss = "";
	for (auto id : ids) ss += s[id];
	sort(begin(ss), end(ss));
	for (auto i = 0; i < ids.size(); ++i) s[ids[i]] = ss[i];
  }
  return s;
}

'''
Disjoint set optimizations
Note that, in the find function, we are using path compression. 
In other words, we "flatten" our hierarchy every time we search,
 so that elements references the parent index directly: 
 ds[i] = find(ds, ds[i]);. Without path compression, 
 you will get TLE on the last test case.

In addition, we can store the count of elements (negated) 
in the parent of the group. Then, when merging two groups, 
we add elements from the smaller group into the larger one. 
That way, we reduce the number of recursive calls for the find 
function to "flatten" newly added elements.

Below is the optimized solution (the changes are for ```if (i != j)```` condition).
 Note that, for this problem, this optimization is not that 
 important (though the runtime went down from 140 to 128 ms for me) 
 since we only have 26 elements. Though, it may help you quite a bit 
 when you deal with larger groups.
'''
string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
  vector<int> ds(s.size(), -1);
  vector<vector<int>> m(s.size());
  for (auto& p : pairs) {
	auto i = find(ds, p[0]), j = find(ds, p[1]);
	if (i != j) {
		if (-ds[i] < -ds[j]) swap(i, j);
		ds[i] += ds[j];
		ds[j] = i;
	}
  }
  for (auto i = 0; i < s.size(); ++i) m[find(ds, i)].push_back(i);
  for (auto ids : m) {
	string ss = "";
	for (auto id : ids) ss += s[id];
	sort(begin(ss), end(ss));
	for (auto i = 0; i < ids.size(); ++i) s[ids[i]] = ss[i];
  }
  return s;
}

# Python implementation

'''
The core of the idea is that if (0, 1) is an exchange 
pair and (0, 2) is an exchange pair, then any 2 in (0, 1, 2) can be exchanged.

This implies, we can build connected components 
where each component is a list of indices that can be 
exchanged with any of them. In Union find terms, we simply 
iterate through each pair, and do a union on the indices in the pair.
At the end of the union of all the pairs, we have 
built connected component of indices that can be exchanged with each other.

Then we build a sorted list of characters for every connected component.

The final step is, we iterate through all 
the indices, and for each index we locate its 
component id and find the sorted list correspondng 
to that component and grab the next lowest character from that list.

This way for every index, we find the lowest possible 
character that can be exchanged and fitted there.
'''
class UF:
	def __init__(self, n): 
		self.p = list(range(n))

	def union(self, x, y): 
		self.p[self.find(x)] = self.find(y)

	def find(self, x):
		if x != self.p[x]: 
			self.p[x] = self.find(self.p[x])
		return self.p[x]

def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
		uf, res, m = UF(len(s)), [], defaultdict(list)
		for x,y in pairs: 
			uf.union(x,y)
		for i in range(len(s)): 
			m[uf.find(i)].append(s[i])
		for comp_id in m.keys(): 
			m[comp_id].sort(reverse=True)
		for i in range(len(s)): 
			res.append(m[uf.find(i)].pop())
		return ''.join(res)