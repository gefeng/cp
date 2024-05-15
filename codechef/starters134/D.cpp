#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr std::array<int64_t, 2> MOD = {(int64_t)998244353, (int64_t)1e9 + 7};
constexpr std::array<int64_t, 2> BASE = {(int64_t)31, (int64_t)37};

struct hash {
    int n;
    std::vector<std::array<int64_t, 2>> h;
    std::vector<std::array<int64_t, 2>> d;

    hash(const std::string& s) : n(s.size() + 1), h(n + 1, {0, 0}), d(n + 1, {1, 1}) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 2; j++) {
                h[i + 1][j] = ((h[i][j] * BASE[j] % MOD[j]) + (s[i] - '(' + 10)) % MOD[j];
                d[i + 1][j] = d[i][j] * BASE[j] % MOD[j];
            }
        } 
    }

    std::array<int64_t, 2> query(int l, int r) {
        std::array<int64_t, 2> res = {h[r + 1][0], h[r + 1][1]};
        for(int i = 0; i < 2; i++) {
            res[i] -= h[l][i] * d[r + 1 - l][i] % MOD[i];
            res[i] += MOD[i];
            res[i] %= MOD[i];
        }
        return res;
    }
};

void run_case() {
    int N;
    std::cin >> N;
    
    std::string S;
    std::cin >> S;

    std::vector<int> s;
    std::vector<int> match(N, -1);
    for(int i = 0; i < N; i++) {
        if(S[i] == '(') {
            s.push_back(i);
        } else {
            match[i] = s.back();
            s.pop_back();
        }
    }

    hash h(S);

    std::vector<std::pair<int, int>> good;
    for(int i = 0; i < N; i++) {
        if(S[i] == ')') {
            good.emplace_back(match[i], i);
        }
    }

    int64_t ans = 0;
    
    std::map<std::array<int64_t, 2>, int> m;
    for(auto [l, r] : good) {
        m[h.query(l, r)] += 1; 
    }

    for(auto [_, v] : m) {
        ans += (int64_t)v * (v - 1) / 2;
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
