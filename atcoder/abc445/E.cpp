#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

constexpr int64_t MOD = static_cast<int64_t>(998244353);
constexpr int INF = static_cast<int>(2e9) + 10;
constexpr int MAX = static_cast<int>(1e7);

std::vector<int> min_f;
std::vector<int64_t> inv;

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
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int, std::vector<std::pair<int, int>>> pf;
    for(int i = 0; i < N; i++) {
        if(pf.find(A[i]) != pf.end()) {
            continue;
        }
        int now = A[i];
        while(now != 1) {
            int f = min_f[now];
            int c = 0;
            while(now % f == 0) {
                now /= f;
                c += 1;
            }
            pf[A[i]].emplace_back(f, c);
        }

        for(auto [f, c] : pf[A[i]]) {
            if(inv[f] == -1) {
                inv[f] = q_pow(f, MOD - 2);
            }
        }
    }

    int64_t ans = 1;
    std::map<int, std::multiset<int>> m;
    for(int i = 0; i < N; i++) {
        for(auto [f, c] : pf[A[i]]) {
            m[f].insert(c);
        }
    }

    for(auto& [f, ms] : m) {
        int c = *ms.rbegin();
        while(c) {
            ans *= f;
            ans %= MOD;
            c -= 1;
        }
    }

    for(int i = 0; i < N; i++) {
        int64_t res = ans;
        for(auto [f, c] : pf[A[i]]) {
            if(c == *m[f].rbegin()) {
                int nc = m[f].size() == 1 ? 0 : *std::prev(std::prev(m[f].end()));
                if(nc < c) {
                    int d = c - nc;
                    res *= q_pow(inv[f], d);
                    res %= MOD;
                }
            } else {
                continue;
            }
        }

        std::cout << res << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    min_f.resize(MAX + 1, INF);
    inv.resize(MAX + 1, -1);

    for(int x = 2; x <= MAX; x++) {
        if(min_f[x] == INF) {
            min_f[x] = x;
            for(int y = x + x; y <= MAX; y += x) {
                min_f[y] = std::min(min_f[y], x);
            }
        }
    }

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
