#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

struct hash {
    std::array<int64_t, 2> mod = {static_cast<int64_t>(998244353), static_cast<int64_t>(1e9) + 7};
    std::array<int64_t, 2> base = {27, 39};
    std::vector<std::vector<int64_t>> h;
    std::vector<std::vector<int64_t>> d;
    
    hash(const std::string& s) {
        int n = s.size();
        h = std::vector<std::vector<int64_t>>(2, std::vector<int64_t>(n + 1, 0));
        d = std::vector<std::vector<int64_t>>(2, std::vector<int64_t>(n + 1, 0));

        d[0][0] = 1;
        d[1][0] = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 2; j++) {
                h[j][i + 1] = ((s[i] - '0' + 1) + (h[j][i] * base[j] % mod[j])) % mod[j];
                d[j][i + 1] = d[j][i] * base[j] % mod[j];
            }
        }
    }

    std::array<int64_t, 2> query(int l, int r) {
        std::array<int64_t, 2> res = {};
        for(int i = 0; i < 2; i++) {
            res[i] = (h[i][r + 1] - (h[i][l] * d[i][r - l + 1] % mod[i]) + mod[i]) % mod[i];
        }
        return res;
    }
};

void run_case() {
    std::string S, T;
    std::cin >> S >> T;

    hash h1(S);
    hash h2(T);

    if(S == T) {
        std::cout << 0 << '\n';
        return;
    }
    
    int n = S.size();
    for(int i = 0; i < n - 1; i++) {
        std::array<int64_t, 2> p1 = h1.query(0, i);
        std::array<int64_t, 2> s2 = h2.query(n - 1 - i, n - 1);
        std::array<int64_t, 2> s1 = h1.query(i + 1, n - 1);
        std::array<int64_t, 2> p2 = h2.query(0, n - 2 - i);

        bool equal = true;
        for(int j = 0; j < 2; j++) {
            if(p1[j] != s2[j] || s1[j] != p2[j]) {
               equal = false; 
            }
        }
        if(equal) {
            std::cout << i + 1 << '\n';
            return;
        }
    }

    std::cout << -1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
