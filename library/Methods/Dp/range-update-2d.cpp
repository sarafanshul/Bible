template< class T >
struct RangeUpdate2D {
  	vector< vector< T > > upd;
  	RangeUpdate2D(ll W, ll H) : upd(W + 2, vector< ll >(H + 2, 0)) {}

	void add(ll x1 , ll y1 , ll x2 , ll y2 ){
		upd[x1][y1]++;
		upd[x2+1][y1]--;
		upd[x1][y2+1]--;
		upd[x2+1][y2+1]++;
	}

	void build(){
		for(ll i = 1; i <= W; i++){
			for(ll j = 0; j <= H; j++) upd[i][j] += upd[i-1][j];
		}
		for(ll i = 0; i <= W; i++){
			for(ll j = 1; j <= H; j++) upd[i][j] += upd[i][j-1];
		}
	}

	T operator[](const ll&x , const ll&y) const { return upd[ x ][ y ] ; }
}