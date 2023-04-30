#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

bool inside(LL x, LL y, LL tx, LL ty, LL bx, LL by) {
    return x >= tx && x <= bx && y >= ty && y <= by; 
}

bool dfs(int N, LL X, LL Y, std::vector<LL>& fib, int f, LL r, LL c, LL h, LL w) {
    if(f == 0) {
        return true;
    } 
    
    LL len = fib[f];

    if(len != std::min(w, h)) {
        return false;
    }

    bool res1 = inside(X, Y, r, c, r + len - 1, c + len - 1);
    bool res2 = false;
    if(h < w) {
        res2 = inside(X, Y, r, c + w - len, r + len - 1, c + w - 1);
    } else {
        res2 = inside(X, Y, r + h - len, c, r + h - 1, c + len - 1);
    }

    if(res1 && res2) {
        return false;
    }
    
    if(!res2) { 
        if(h < w) {
            return dfs(N, X, Y, fib, f - 1, r, c, h, w - len);
        } else {
            return dfs(N, X, Y, fib, f - 1, r, c, h - len, w);
        }
    } else {
        if(h < w) {
            return dfs(N, X, Y, fib, f - 1, r, c + len, h, w - len);
        } else {
            return dfs(N, X, Y, fib, f - 1, r + len, c, h - len, w);
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;
    
    LL X, Y;
    std::cin >> X >> Y;

    std::vector<LL> fib(N + 2);
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i <= N + 1; i++) {
        fib[i] = fib[i - 2] + fib[i - 1];
    }

    std::cout << (dfs(N, X, Y, fib, N, 1, 1, fib[N], fib[N + 1]) ? "YES" : "NO") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
