#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 2000;

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum += A[i];
    }

    auto check = [&](int s) {
        if(s % 2 == 1) {
            return 0;
        }

        int t = s / 2;
        std::vector<int> dp(t + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < N; i++) {
            std::vector<int> ndp(t + 1, 0);
            for(int j = 0; j <= t; j++) {
                ndp[j] = dp[j];
                if(j - A[i] >= 0) {
                    ndp[j] = ndp[j] || dp[j - A[i]];
                }
            }
            std::swap(dp, ndp);
        }
        return dp[t];
    };

    if(!check(sum)) {
        std::cout << 0 << '\n';
        return;
    }

    while(true) {
        for(int i = 0; i < N; i++) {
            if(A[i] % 2 == 1) {
                std::cout << 1 << '\n' << i + 1 << '\n';
                return;
            }
            A[i] /= 2;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
