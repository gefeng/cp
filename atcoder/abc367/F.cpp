#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e13) + 7;
constexpr int64_t BASE = int64_t(2e5) + 7;

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<int64_t> h(N + 1, 1);
    for(int i = 1; i <= N; i++) {
        h[i] = h[i - 1] * BASE % MOD;
    }

    std::vector<int64_t> psum1(N + 1, 0);
    std::vector<int64_t> psum2(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        psum1[i] = psum1[i - 1] + h[A[i - 1]];
        psum2[i] = psum2[i - 1] + h[B[i - 1]];
    }

    for(int i = 0; i < Q; i++) {
        int L1, R1, L2, R2;
        std::cin >> L1 >> R1 >> L2 >> R2;
        
        L1 -= 1;
        R1 -= 1;
        L2 -= 1;
        R2 -= 1;

        int64_t sum1 = psum1[R1 + 1] - psum1[L1];
        int64_t sum2 = psum2[R2 + 1] - psum2[L2];
            
        std::cout << (sum1 == sum2 ? "Yes" : "No") << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
