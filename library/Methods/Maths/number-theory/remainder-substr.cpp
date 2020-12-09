// use -> to calculate remainder of number by X from start to i->[1 .. N]
 
 /*
At first, let’s check all prefixes of specified number — 
	do they have remainder 0 when divided by the a? 
	It can be done with asymptotic behavior O(N), 
	where N -length of specified number C. 
	If we have remainder of division by a of prefix, 
	which ends in position pos, 
	we can count remainder in position 
		pos + 1: rema[pos + 1] = (rema[pos] * 10 + C[pos + 1]) % a.

Then we need to check suffixes.
If we have remainder of division by b of suffix, which begin in position pos, 
we can count remainder of position 
	pos - 1: remb[pos - 1] = (C[pos - 1] * P + remb[pos]) % b, 
	where P — it is 10^(L - 1) module b, L — length of suffix (P we can count parallel).
 
 ref PROB - https://codeforces.com/contest/490/problem/C
 */

long long l[MAXN], r[MAXN];

void calc(string s ,long long a,long long b){
	long long n = s.size();
    // read discription or change a = b;
    long long num = 0;
    for (long long i = 0; i < n; i ++) {
        num = num * 10 + (s[i] - '0');
        num %= a;
        l[i] = num;
    }
    long long wei = 1;
    num = 0;
    for (long long i = n - 1; i >= 0; i --) {
        num = num + wei * (s[i] - '0');
        num %= b;
        r[i] = num;
        wei = wei * 10 % b;
    }
}