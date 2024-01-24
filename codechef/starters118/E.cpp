#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)1e9 + (int64_t)7;

void run_case() {
    // a = (ending with a, has b)
    // b = (ending with a, has no b);
    // c = (ending with b, has b)
    
    std::string S;
    std::cin >> S;

    int n = S.size();
    int64_t a = 0;
    int64_t b = 0;
    int64_t c = 0;

    for(int i = 0; i < n; i++) {
        int64_t na = a;
        int64_t nb = b;
        int64_t nc = c;
        if(S[i] == 'a') {
            na += c;
            na %= MOD;
            nb += (b + 1) % MOD;
            nb %= MOD;
        } else {
            nc += a;
            nc %= MOD;
            nc += b;
            nc %= MOD;
        }

        std::swap(a, na);
        std::swap(b, nb);
        std::swap(c, nc);
    }

    std::cout << (b + c) % MOD << '\n';
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
