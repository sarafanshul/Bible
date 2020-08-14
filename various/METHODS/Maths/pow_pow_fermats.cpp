/*
Naive approach will not work -> pow(a ,pow(b ,c)) != a^(b^(c))

According the Fermat's little
a(M - 1) = 1 (mod M) if M is a prime.

So if we rewrite BC as x*(M-1) + y, then the
    task of computing ABC becomes Ax*(M-1) + y
    which can be written as Ax*(M-1)*Ay.
    From Fermat's little theorem, we know Ax*(M-1) = 1.
    So task of computing ABC reduces to computing Ay

What is the value of y?
    From BC = x * (M - 1) + y,
    y can be written as BC % (M-1)

We can easily use the above theorem such that we can get
    A ^ (B ^ C) % M = (A ^ y ) %  M

Now we only need to find two things as:-
    1. y = (B ^ C) % (M - 1)
    2. Ans = (A ^ y) % M

*/


#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define int unsigned long long

using namespace std;

const unsigned MOD = 1e9+7;
const unsigned MAXN = 101;
const unsigned MAXM = 1e6+7;

inline void fasterLLDivMod(unsigned long long x, unsigned y, unsigned &out_d, unsigned &out_m) {
    unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x, d, m;
    #ifdef __GNUC__
    asm(
        "divl %4 \n\t"
        : "=a" (d), "=d" (m)
        : "d" (xh), "a" (xl), "r" (y)
    );
    #else
    __asm {
        mov edx, dword ptr[xh];
        mov eax, dword ptr[xl];
        div dword ptr[y];
        mov dword ptr[d], eax;
        mov dword ptr[m], edx;
    };
    #endif
    out_d = d; out_m = m;
}
inline unsigned mod(unsigned long long x, unsigned y = MOD) {
    unsigned dummy, r;
    fasterLLDivMod(x, y, dummy, r);
    return r;
}
inline unsigned mod1(unsigned long long x, unsigned y = MOD-1) {
    unsigned dummy, r;
    fasterLLDivMod(x, y, dummy, r);
    return r;
}

int power(int x ,int y) {  
    if(x == 0 && y == 0 )return 1;
    int res = 1;
    x = mod(x);
    if (x == 0) return 0;
    while (y > 0) {  
        if (y & 1) res = mod(res*x);  
        y = y>>1;
        x = mod(x*x);  
    }
    return mod(res);  
}  

int power1(int x ,int y) {  
    if(x == 0 && y == 0 )return 1;
    int res = 1;
    x = mod1(x);
    if (x == 0) return 0;
    while (y > 0) {  
        if (y & 1) res = mod1(res*x);  
        y = y>>1;
        x = mod1(x*x);  
    }
    return mod1(res);  
}

inline int _pow(int a ,int b ,int c){return (power(a ,power1(b ,c)));}


int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int a ,b ,c;
    cin >> a >> b >> c;
    cout << _pow(a ,b ,c) << "\n";
    
    return 0;
}