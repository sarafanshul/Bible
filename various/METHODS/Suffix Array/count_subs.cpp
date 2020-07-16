// https://codeforces.com/edu/course/2/lesson/2/2

// O(NlogN)
// using counting sort

#include <bits/stdc++.h>

using namespace std;

void count_sort(vector<int> &p ,vector<int> &c){
	int n = p.size();
	// counting sort twice
	{
		vector<int> cnt(n);
		for (auto x: c){
			cnt[x]++;
		}
		vector<int> p_new(n);
		vector<int> pos(n);
		pos[0] = 0;
		for(int i = 1; i <n ;i++){
			pos[i] = pos[i-1] + cnt[i-1];
		}
		for (auto x : p){
			int i = c[x];
			p_new[pos[i]] = x;
			pos[i]++;
		}
		p = p_new;
	}
}

int bs_upper_bound(vector<int> &p ,string &s ,string &q) {
    int l = 0 ,h = s.size() ,mid ,ck ,n1 = q.size();
    while (l < h) {
        mid = l + ((h - l) / 2);
        ck = q.compare(s.substr(p[mid] ,n1));
        if (0 <= ck) { // change
            l = mid + 1;
        } else {
            h = mid;
        }
    }
    return l;
}

int bs_lower_bound(vector<int> &p ,string &s ,string &q) {
    int l = 0 ,h = s.size() ,mid ,ck ,n1 = q.size();
    while (l < h) {
        mid = l + ((h - l) / 2);
        ck = q.compare(s.substr(p[mid] ,n1));
        if (0 >= ck) { // change
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int check( vector<int> &p , string s1 ,int n){
	string q;
	cin >> q;
	if (q.compare(s1) == 0) return 1;
	long long count = 0;
	// cout <<bs_upper_bound(p ,s1 ,q) << "  " << bs_lower_bound(p ,s1 ,q)<<"\n"; 
	int up = bs_upper_bound(p ,s1 ,q) ,lo = bs_lower_bound(p ,s1 ,q);
	if (up == lo) return 0;
	count = up - lo + 1;
	return (int)count;
}

int main(){
	string s ,s1;
	cin >> s;
	s1 = s;
	s += "$";
	int n = s.size();
	vector<int> p(n) ,c(n);
	{
		// k = 0
		vector<pair<char ,int>> a(n);
		// save characters and positions then sort
		for (int i = 0; i < n ; i++) a[i] = {s[i] ,i};
		sort(a.begin() ,a.end());

		// save array [p]
		for (int i = 0; i < n; ++i) p[i] = a[i].second;
		// create array [c]
		c[p[0]] = 0;
		for(int i = 1 ; i < n; ++i){
			if (a[i].first == a[i-1].first) {
				c[p[i]] = c[p[i-1]];
			} else {
				c[p[i]] = c[p[i-1]] + 1;
			}
		}
	}
	// now transitions of k
	int k = 0;
	while ((1<<k) < n){
		// k -> K + 1
		
		for(int i = 0 ; i< n ;i++){
			p[i] = (p[i] - (1<<k) + n) % n;
		}

		count_sort(p ,c);
		
		vector<int> c_new(n);
		c_new[p[0]] = 0;
		for(int i = 1 ; i < n; ++i){
			pair<int ,int> prev = {c[p[i - 1]] ,c[(p[i - 1] + (1<<k)) % n]};
			pair<int ,int> now = {c[p[i]] ,c[(p[i] + (1<<k)) % n]};
			if (now == prev) {
				c_new[p[i]] = c_new[p[i-1]];
			} else {
				c_new[p[i]] = c_new[p[i-1]] + 1;
			}
		}
		c = c_new;
		k++;
	}
	int t = 0;
	cin >> t ;
	while( t-- ){
		cout << check(p ,s1 ,n) << "\n";
	}
}

