// #include <bits/stdc++.h>

// using namespace std;
// struct mineq_operator{
//     int tempVal=1000;
//     inline mineq_operator operator<<(int& x) {
//         this->tempVal = x;
//         return *this;
//     } inline mineq_operator operator>>(int& x) {
//         x = (x>tempVal)?tempVal:x;
//         return *this;
//     }
// };
// mineq_operator __me;
// inline void operator<<(int& x, mineq_operator& b) {
//     b.tempVal = x;
// }

// #define minEqual <<__me;__me>>

// compressed format

#include <bits/stdc++.h>

using namespace std;
struct mineq_operator {int tempVal=1000;inline mineq_operator operator<<(int& x) {this->tempVal = x;return *this;}inline mineq_operator operator>>(int& x) {x = min(x, tempVal);return *this;}};
mineq_operator __me; inline void operator<<(int& x, mineq_operator& b) {b.tempVal = x;}
#define minEqual <<__me;__me>>

// For use it like x = min(x, y); 
// just write y minEqual x;

signed main() {
    int x = 3, y = 2;
    y minEqual x;
    cout << x << ' ' << y << endl;
}