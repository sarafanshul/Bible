const uint32_t MOD = 1e9+7;

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