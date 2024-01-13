#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)2e9;

void run_case() {
    int N, X, K;
    std::cin >> N >> K >> X;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end(), std::greater<int>());
    
    std::vector<int> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] + A[i];
    }

    int max_sum = -INF;
    for(int i = 0; i <= K; i++) {
        int x = std::min(N - i, X); 
        int sum = -(psum[i + x] - psum[i]);
        sum += psum[N] - psum[i + x];
        max_sum = std::max(max_sum, sum);
    }

    std::cout << max_sum << '\n';
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
