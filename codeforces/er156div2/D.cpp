#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)998244353;

int64_t q_pow(int64_t x, int64_t y) {
    int64_t res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::string S;
    std::cin >> S;
    
    std::vector<int64_t> inv(N + 1, 1);
    for(int i = 2; i <= N; i++) {
        inv[i] = q_pow(i, MOD - 2);
    }

    int64_t prod = 1;
    if(S[0] == '?') {
        for(int i = 1; i < N - 1; i++) {
            if(S[i] == '?') {
                prod *= i;
                prod %= MOD;
            }
        }
        std::cout << 0 << '\n';
    } else {
        for(int i = 0; i < N - 1; i++) {
            if(S[i] == '?') {
                prod *= i;
                prod %= MOD;
            } 
        }

        std::cout << prod << '\n';
    }
    
    for(int i = 0; i < M; i++) {
        int P;
        char C;
        std::cin >> P >> C;
        P -= 1;

        int64_t res = 1;
        if(S[P] != '?' && C == '?' && P != 0) {
            prod *= P;
            prod %= MOD;
        } else if(S[P] == '?' && C != '?' && P != 0) {
            prod *= inv[P];
            prod %= MOD;
        }

        S[P] = C;
        res = S[0] == '?' ? 0 : prod;
        std::cout << res << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
