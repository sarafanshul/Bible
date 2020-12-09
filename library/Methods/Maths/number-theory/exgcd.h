#pragma once

// a/ ax + by = gcd(x,y)
template<typename T = long long>
T exgcd(T x ,T y ,T &a ,T &b){
	bool f = 0;
	T t ,la = 1 ,lb = 0 ,ra = 0 ,rb = 1;
	while(x%y){
		if(!f){
			la -= x/y*ra ,lb-= x/y*rb;
		} else{
			ra -= x/y*la ,rb -= x/y*lb;
		}
		t = x ,x = y ,y = t%y;
		f ^= 1;
	}
	if(!f) a = ra ,b = rb;
	else a = la ,b = lb;
	return y;
}
