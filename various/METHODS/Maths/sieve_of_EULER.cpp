//Euler's sieve progressively removes, from all the natural numbers above 1, all the multiples of primes as the primes are found by it, starting with 2.


const long long M = 1.5e7;

long long  mindiv[M] ,p[MAXN] ,tot ,num[M];

void pre(){
	for(int i = 2 ; i < M ;i++){
		if(!mindiv[i])mindiv[i] = p[++tot] = i;
		for(int j = 1 ,y ;( j <= tot && p[j] <= mindiv[i] && (y = p[j]*i) < M) ; j++){
			mindiv[y] = p[j];
		}
	}
}
