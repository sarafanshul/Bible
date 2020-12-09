
map<long long, long long> _keys;

bool _hash_t[MAXN];
void pre(){
	memset(_hash_t ,1 ,sizeof(_hash_t));
	for(ll p = 2 ;p*p < MAXN ;p++){
		if(_hash_t[p]){for(ll i = p*2 ; i < MAXN ;i += p){_hash_t[i] = 0;}}
	}
}


ll divCount(ll a){
    if(_keys.find(a) != _keys.end()) return _keys[a];
	ll tot = 1LL ,count = 0;
	for(ll p = 2 ;p <= a; p++){
		if(_hash_t[p]){
			count = 0;
			if(a%p == 0){ while(a%p == 0){ a = a/p;count++; } }
			tot = (tot * (count + 1))%MOD;
		}
	}
	_keys[a] = tot;
	return tot;
}

	// pre();
	// cout << divCount((ll)1e6);

