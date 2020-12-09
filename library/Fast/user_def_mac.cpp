// 1 rep()

// First of all, you don't need to name the type you want to use. Second of all it goes forwards and backwards based on (begin > end) condition. e.g. rep(i, 1, 10) is 1, 2, ..., 8, 9 and rep(i, 10, 1) is 9, 8, ..., 2, 1
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


vector<int> v = {4, 5, 6, 4, 8};
rep(it, end(v), begin(v))
    cout << *it << ' ';
// prints "8 4 6 5 4"


// 2 endline without abruptly defining it
for(i = 1; i <= n; i++)
    for(j = 1; j <= m; j++)
        cout << a[i][j] << " \n"[j == m];
// And here is the reason: " \n" is a char*, " \n"[0] is ' ' and " \n"[1] is '\n'.
