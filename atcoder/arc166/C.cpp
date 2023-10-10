#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = (int)1e6;
constexpr int64_t MOD = (int64_t)998244353;

std::vector<int64_t> fib(MAX * 2 + 2, 1);
std::vector<int64_t> pprod(MAX + 1, 1);

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
    int H, W;
    std::cin >> H >> W;

    int64_t ans = 0;
    if(W >= H) {
        ans = (pprod[H] * pprod[H] % MOD) * q_pow(fib[2 * H + 1], W - H) % MOD;
    } else {
        ans = (pprod[W] * pprod[W] % MOD) * q_pow(fib[2 * W + 1], H - W) % MOD;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for(int i = 2; i < MAX * 2 + 2; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }

    for(int i = 1; i <= MAX; i++) {
        pprod[i] = pprod[i - 1] * fib[i * 2] % MOD;
    }

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
