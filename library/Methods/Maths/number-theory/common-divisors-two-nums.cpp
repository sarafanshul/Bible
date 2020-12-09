// calculate the gcd of given two numbers, and then count divisors of that gcd
vector<long long> v; 
template<typename T>
void common_div(T a ,T b){
 	T g = __gcd(a,b);
	for (T i = 1; i*i <= g; i++) {
		if (g%i==0) {
			v.push_back(i); v.push_back(g/i);
		}
	}
}