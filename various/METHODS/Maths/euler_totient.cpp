// https://codeforces.com/blog/entry/8989
// https://codeforces.com/blog/entry/22229
// https://cp-algorithms.com/algebra/phi-function.html

const long long MAXN = 1e6;

vector<long long> phi(MAXN);

void euler_phi(){
	iota(ALL(phi) ,0); // phi[i] = i;

	for(int i = 2 ; i < MAXN; i++){
		if(phi[i] == i){
			for(int j = i ;j < MAXN ;j += i){
				phi[j] -= phi[j] / i;
			}
		}
	}
}