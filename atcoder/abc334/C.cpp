#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)1e18;

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(K);
    
    for(int i = 0; i < K; i++) {
        std::cin >> A[i]; 
    }

    std::sort(A.begin(), A.end());

    int64_t ans = 0;
    if(K % 2 == 0) {
        for(int i = 0; i < K; i += 2) {
            ans += std::abs(A[i] - A[i + 1]);
        } 
    } else {
        if(K == 1) {
            std::cout << 0 << '\n';
            return;
        }

        ans = INF;
        std::vector<int64_t> psum1(K + 1, 0);
        std::vector<int64_t> psum2(K + 1, 0);
        for(int i = 0; i < K; i++) {
            psum1[i + 1] = i % 2 == 1 ? psum1[i] + A[i] - A[i - 1] : psum1[i];
        }

        for(int i = 1; i < K; i++) {
            psum2[i + 1] = i % 2 == 0 ? psum2[i] + A[i] - A[i - 1] : psum2[i];
        }

        for(int i = 0; i < K; i++) {
            if(i == 0) {
                ans = std::min(ans, psum2[K]);
            } else if(i == K - 1) {
                ans = std::min(ans, psum1[K]);
            } else {
                if(i % 2 == 0) {
                    ans = std::min(ans, psum1[i] + psum2[K] - psum2[i + 1]);
                } else {
                    ans = std::min(ans, psum1[i - 1] + psum2[K] - psum2[i + 2] + A[i + 1] - A[i - 1]);
                }
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
