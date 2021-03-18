ll countbits( ll x ){
	x++ ; ll ret = x / 2 , pow_2 = 2 , tot ;
	while(pow_2 <= x){
		tot = x / pow_2 ;
		ret += (tot / 2)*pow_2 + ((tot & 1) ? (x % pow_2) : 0) ;
		pow_2 <<= 1;
	}
	return ret ;
}