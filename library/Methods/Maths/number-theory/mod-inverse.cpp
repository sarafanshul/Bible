ll modInverse(ll a, ll m)  { 
	ll m0 = m; 
	ll y = 0, x = 1; 
	if (m == 1)  return 0; 
	while (a > 1) { 
		ll q = a / m; 
		ll t = m; 
 		m = a % m, a = t; 
		t = y; 
		y = x - q * y; 
		x = t; 
	} 
	if (x < 0)  x += m0; 
	return x; 
} 