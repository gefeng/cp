#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

constexpr int64_t MOD = static_cast<int64_t>(1e6) + 3;
constexpr int MAX = static_cast<int>(1e6) + 3;

std::vector<int64_t> fact(MAX + 1, 1);
std::vector<int64_t> invf(MAX + 1, 1);

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
    std::vector<int> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<std::vector<std::pair<int, int>>> seq(N);
    for(int i = 0; i < N; i++) {
        int x = A[i];
        int y = B[i];
        while(y != x) {
            if(y % 2 == 1) {
                y -= 1;
                seq[i].emplace_back(0, 1);
            } else {
                if(y / 2 >= x) {
                    seq[i].emplace_back(1, y / 2);
                    y /= 2;
                } else {
                    seq[i].emplace_back(0, y - x);
                    y = x;
                }
            }
        }
        std::ranges::reverse(seq[i]);
    }

    int64_t ans = 0;
    int64_t cnt = 1;
    while(true) {
        bool mul = true;
        for(int i = 0; i < N; i++) {
            if(seq[i].empty()) {
                mul = false;
            } else {
                bool found = false;
                for(int j = seq[i].size() - 1; j >= 0; j--) {
                    if(seq[i][j].first == 1) {
                        found = true; 
                        break;
                    }
                }
                if(!found) {
                    mul = false;
                }
            }
        }

        int64_t tot = 0;
        std::vector<int64_t> add(N, 0);
        if(!mul) {
            for(int i = 0; i < N; i++) {
                for(int j = seq[i].size() - 1; j >= 0; j--) {
                    ans += seq[i][j].second;
                    tot += seq[i][j].second;
                    add[i] += seq[i][j].second;
                }
            }
        } else {
            for(int i = 0; i < N; i++) {
                while(seq[i].back().first != 1) {
                    ans += seq[i].back().second;
                    tot += seq[i].back().second;
                    add[i] = seq[i].back().second;
                    seq[i].pop_back();
                }
                seq[i].pop_back();
            }
            ans += 1;
        }
        for(int i = 0; i < N; i++) {
            if(add[i]) {
                if(tot >= MAX) {
                    cnt = 0;
                } else {
                    cnt *= (fact[tot] * invf[add[i]] % MOD) * invf[tot - add[i]] % MOD;
                    cnt %= MOD;
                }
                tot -= add[i];
            }
        }
        if(!mul) {
            break;
        }
    }

    std::cout << ans << ' ' << cnt << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    for(int i = 1; i <= MAX; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
