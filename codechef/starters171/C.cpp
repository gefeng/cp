#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;

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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = 1;
    bool fixed = false;
    int l = 0;
    int r = N - 1;
    while(l < r) {
        if(A[l] && A[r] && A[l] != A[r]) {
            fixed = true;
        }
        l += 1;
        r -= 1;
    }

    for(int i = 0; i < N; i++) {
        if(A[i] == 0) {
            ans *= K;
            ans %= MOD;
        }
    }

    if(!fixed) {
        l = 0;
        r = N - 1;
        int64_t cnt = 0;
        while(l < r) {
            if(A[l] == 0 && A[r] == 0) {
                cnt += 1;  
            }
            l += 1;
            r -= 1;
        }

        int64_t x = 1;
        int64_t y = 1;
        for(int i = 0; i < cnt; i++) {
            x *= int64_t(K) * K % MOD;
            x %= MOD;
        }

        for(int i = 0; i < cnt; i++) {
            y *= K;
            y %= MOD;
        }

        if(N % 2 == 1 && A[N / 2] == 0) {
            x *= K;
            x %= MOD;
            y *= K;
            y %= MOD;
        }

        x -= y;
        x += MOD;
        x %= MOD;
        
        ans -= x * q_pow(2, MOD - 2) % MOD;
        ans += MOD;
        ans %= MOD;
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
