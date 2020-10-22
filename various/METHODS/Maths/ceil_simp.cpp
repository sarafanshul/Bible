// note that for positive integers a and b, 
// 		⌈a/b⌉ = ⌊(a+b−1)/b⌋

template<typename T = long long >
inline T __ceil(T a ,T b){return (a + b - 1)/b;}
