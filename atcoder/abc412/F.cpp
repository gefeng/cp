#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(998244353);

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
    int N, C;
    std::cin >> N >> C;
    C -= 1;
    
    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
        A[i].second = i;
        if(i == C) {
            A[i].first += 1;
        }
    }

    std::sort(A.begin(), A.end());

    std::vector<int> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] + A[i].first;
    }

    std::vector<int64_t> ds(N, 0);
    int64_t rev_sum = q_pow(psum[N] - 1, MOD - 2);
    for(int i = N - 1; i >= 0; i--) {
        int j = std::upper_bound(A.begin(), A.end(), A[i].first, [](int v, auto& x) {
                    return v < x.first;
                }) - A.begin(); 

        int64_t suffix = j == N ? 0 : ds[j];   

        int64_t p_1 = (psum[j] - A[i].first) * rev_sum % MOD; 
        int64_t p_2 = A[i].first * rev_sum % MOD;
        int64_t f = ((suffix + 1) % MOD) * q_pow((1 - p_1 + MOD) % MOD, MOD - 2) % MOD;

        ds[i] = ((i == N - 1 ? 0 : ds[i + 1]) + (f * p_2 % MOD)) % MOD;
        if(C == A[i].second) {
            std::cout << f << '\n';
            return;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
