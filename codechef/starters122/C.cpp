#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int64_t MOD = (int64_t)1e9 + 7;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> A(N, std::vector<int>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> A[i][j];
        }
    }

    int k = (N * N + N) / 2;

    std::map<int, std::vector<std::pair<int, int>>> m;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) {
                if(A[i][i] && (A[i][i] <= k - N || A[i][i] > k)) {
                    std::cout << 0 << '\n'; 
                    return;
                }
            } else {
                if(A[i][j] && A[i][j] > k - N && A[i][j] <= k) {
                    std::cout << 0 << '\n';
                    return;
                }
                if(A[i][j] && A[j][i] && A[i][j] % k != A[j][i] % k) {
                    std::cout << 0 << '\n';
                    return;
                }

                if(A[i][j]) {
                    m[A[i][j] % k].emplace_back(i, j);
                }
            }
        }
    }

    for(auto& [r, v] : m) {
        if(v.size() > 2) {
            std::cout << 0 << '\n';
            return;
        }
        if(v.size() == 2) {
            if(v[0].first != v[1].second || v[0].second != v[1].first) {
                std::cout << 0 << '\n';
                return;
            }
        }
    }

    int64_t ans = 1;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(A[i][i] == 0) {
            cnt += 1;
        }
    }

    for(int i = 0; i < cnt; i++) {
        ans *= (cnt - i);
        ans %= MOD;
    } 

    if(N == 1) {
        std::cout << ans << '\n';
        return;
    }

    int64_t f = 1;
    int64_t x = 1;
    int64_t y = 1;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(i == j) {
                continue;
            }
            if(A[i][j] == 0 && A[j][i] == 0) {
                x *= f; 
                x %= MOD;
                f += 1;
                y *= 2;
                y %= MOD;
            }
        }
    }
    ans *= x * y % MOD;
    ans %= MOD;

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
