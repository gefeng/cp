#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)2e18;

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    std::vector<int> B(N + 1);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N + 1; i++) {
        std::cin >> B[i];
    }

    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        sum += std::abs(A[i] - B[i]);
    }

    int64_t ans = INF;
    for(int i = 0; i < N; i++) {
        int64_t cost = sum + 1;
        if(std::min(A[i], B[i]) <= B.back() && std::max(A[i], B[i]) >= B.back()) {
            ans = std::min(ans, cost); 
        } else {
            ans = std::min(ans, cost + std::min(std::abs(A[i] - B.back()), std::abs(B[i] - B.back())));
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
