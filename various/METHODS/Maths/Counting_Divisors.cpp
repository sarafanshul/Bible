#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e6 +7;

vector<ll> num_div(MAXN);
vecotr<vector<ll>> divs(MAXN ,vector<ll>(0));

void num_divisors(){
	for (int i = 1; i <= MAXN; i++)
        for (int j = i; j <= MAXN; j += i)
            num_div[j]++;
}

void divisors(){
	for(int i = 1; i <= MAXN; i++){
    	for(int j = i; j <= MAXN ; j += i){
        	divisors[j].push_back(i);
    	}
	}
}