#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;

int64_t gcd(int64_t a, int64_t b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int64_t lcm(int64_t a, int64_t b) {
    return a * b / gcd(a, b);
}

void run_case() {
    int64_t B, Q, Y, C, R, Z;
    std::cin >> B >> Q >> Y >> C >> R >> Z;

    int64_t bl = B;
    int64_t br = B + (Y - 1) * Q;
    int64_t cl = C;
    int64_t cr = C + (Z - 1) * R;

    if(R % Q != 0 || std::abs(B - C) % Q != 0 || cl < bl || cr > br) {
        std::cout << 0 << '\n';
        return;
    }

    if(cl == bl || br == cr || cl - R < bl || cr + R > br) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<int64_t> da;
    for(int64_t f = 1; f * f <= R; f++) {
        if(R % f == 0) {
            da.push_back(f);
            if(R / f != f) {
                da.push_back(R / f);
            }
        }
    }

    std::sort(da.begin(), da.end());
    
    int64_t ans = 0;
    for(int64_t p : da) {
        if(lcm(p, Q) != R) {
            continue;
        }

        int64_t al = C - R + p;
        int64_t ar = C;

        int64_t k1 = (C + (Z - 1) * R - al) / p + 1;
        int64_t k2 = (C + Z * R - al) / p + 1;

        int64_t x = k2 - k1;
        int64_t t = (ar - al + p) / p;
        x %= MOD;
        t %= MOD;
        
        ans += x * t % MOD;
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
