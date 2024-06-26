#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

struct hash {
    const std::array<int64_t, 3> BASE = {(int64_t)31, (int64_t)37, (int64_t)61}; 
    const std::array<int64_t, 3> MOD = {(int64_t)1e9 + 7, (int64_t)1e9 + 9, (int64_t)998244353};

    int n;
    std::vector<std::array<int64_t, 3>> h;
    std::vector<std::array<int64_t, 3>> d;

    hash(const std::string& s) : n(s.size()), h(n + 1, {0, 0, 0}), d(n + 1, {1, 1, 1}) {
        std::array<int64_t, 3> cur_h = {};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 3; j++) {
                cur_h[j] = ((cur_h[j] * BASE[j] % MOD[j]) + s[i] - 'a') % MOD[j];
            }
            h[i + 1] = cur_h;
        } 
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 3; j++) {
                d[i][j] = d[i - 1][j] * BASE[j] % MOD[j];
            } 
        }
    }
    std::array<int64_t, 3> query(int l, int r) {
        std::array<int64_t, 3> res = {};
        for(int i = 0; i < 3; i++) {
            int64_t h1 = h[r + 1][i];
            int64_t h2 = h[l][i] * d[(r - l + 1)][i] % MOD[i];
            res[i] = (h1 - h2 + MOD[i]) % MOD[i];
        }
        return res;
    }
};

void run_case() {
    std::string S;
    std::cin >> S;

    int n = S.size();
    if(n % 2 == 1) {
        std::cout << 0 << '\n';
        return;
    }

    hash h(S);
    int ans = 0;
    for(int i = 0; i <= n; i++) {
        int l = i;
        int r = n - i;
        if(l % 2 == 0 && r % 2 == 0) {
            std::array<int64_t, 3> h1 = h.query(0, l / 2 - 1);
            std::array<int64_t, 3> h2 = h.query(l / 2, l - 1);
            std::array<int64_t, 3> h3 = h.query(l, l + r / 2 - 1);
            std::array<int64_t, 3> h4 = h.query(l + r / 2, n - 1);
            if(h1 == h2 && h3 == h4) {
                ans += 1;
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
