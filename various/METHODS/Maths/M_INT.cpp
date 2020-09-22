const uint64_t MOD = 998244353;
struct mint {
  	ll x; // typedef long long ll;
  	mint(ll x=0):x((x%MOD+MOD)%MOD){}
  	mint operator-() const { return mint(-x);}
  	mint& operator+=(const mint a) {
    	if ((x += a.x) >= MOD) x -= MOD;
    	return *this;
  	}
  	mint& operator-=(const mint a) {
	  if ((x += MOD-a.x) >= MOD) x -= MOD;
    	return *this;
  	}
	mint& operator*=(const mint a) { (x *= a.x) %= MOD; return *this;}
	mint operator+(const mint a) const { return mint(*this) += a;}
	mint operator-(const mint a) const { return mint(*this) -= a;}
	mint operator*(const mint a) const { return mint(*this) *= a;}
	mint pow(ll t) const {
    	if (!t) return 1;
    		mint a = pow(t>>1);
    		a *= a;
    		if (t&1) a *= *this;
    		return a;
  		}

  	// for prime MOD
  	mint inv() const { return pow(MOD-2);}
  	mint& operator/=(const mint a) { return *this *= a.inv();}
  	mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}



