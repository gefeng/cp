#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int>(2e9) + 10;

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int min_v = INF;
    int max_v = 0;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(min_v != INF) {
            if(std::abs(A[i] - min_v) > K || std::abs(A[i] - max_v) > K) {
                ans += 1;
                min_v = INF;
                max_v = 0;
                continue;
            }
        } 

        min_v = std::min(min_v, A[i]);
        max_v = std::max(max_v, A[i]);
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
