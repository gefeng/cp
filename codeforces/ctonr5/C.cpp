#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = 1e9;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::vector<int> dp1(N + 1, 0); // maximum removal through first i balls
    std::vector<int> dp2(N + 1, INF); // minimum ball left for ball with color i
    
    for(int i = 1; i <= N; i++) {
        dp1[i] = dp1[i - 1];

        if(dp2[A[i - 1]] != INF) {
            dp1[i] = std::max(dp1[i], i - dp2[A[i - 1]]);
        }

        dp2[A[i - 1]] = std::min(dp2[A[i - 1]], i - 1 - dp1[i - 1]);
    }

    std::cout << dp1[N] << '\n'; 
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
