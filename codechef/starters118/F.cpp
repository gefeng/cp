#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)1e9 + (int64_t)7;
constexpr int64_t BASE = 31;

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
    int N, K;
    std::cin >> N >> K;

    std::string S;
    std::cin >> S;

    bool unique = true;
    for(int i = 0; i < N; i++) {
        if(S[i] != S[0]) {
            unique = false;
            break;
        }
    }

    if(unique) {
        std::cout << ((q_pow(2, K) * (int64_t)N % MOD) - (N - 1) + MOD) % MOD << '\n';
        return;
    }

    std::string s = S + S;
    std::reverse(s.begin() + N, s.end());
    s = s + S;

    int64_t h = 0;
    int64_t t = 0;
    for(int i = 0; i < N; i++) {
        h = h * BASE % MOD + s[i] - 'a' + 1;
        h %= MOD;
    }

    t = h;
    h = 0;
    int64_t d = 1;
    int64_t repeat = q_pow(2, K - 1);
    int64_t ans = 0;
    for(int l = 0, r = 0; r < N * 3 - 1; r++) {
        h = h * BASE % MOD + s[r] - 'a' + 1;
        h %= MOD;

        if(r - l < N) {
            d *= BASE;
            d %= MOD;
        }
        
        if(r - l + 1 > N) {
            h -= d * (s[l] - 'a' + 1) % MOD;
            h += MOD;
            h %= MOD;
            l += 1;
        }

        if(r - l + 1 == N) {
            if(h == t) {
                ans += l < N + 1 ? repeat : (repeat - 1 + MOD) % MOD;
                ans %= MOD;
            } 
        }
    }

    std::cout << ans << '\n';
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
