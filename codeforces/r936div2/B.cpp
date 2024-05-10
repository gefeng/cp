#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)1e9 + 7;

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t sum = 0;
    int64_t max_s = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i];
        max_s = std::max(max_s, sum);
        sum = std::max((int64_t)0, sum);
    }

    sum = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i];
        sum += MOD;
        sum %= MOD;
    }

    sum -= (max_s % MOD);
    sum += MOD;
    sum %= MOD;
    for(int i = 0; i < K; i++) {
        max_s += max_s;
        max_s %= MOD;
    }

    sum += max_s;
    sum %= MOD;
    
    std::cout << sum << '\n';
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
