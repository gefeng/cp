#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
    }

    for(int i = 0; i < N; i++) {
        std::cin >> A[i].second;
    }

    std::sort(A.begin(), A.end(), [](const auto& x, const auto& y) {
                return std::min(x.first, x.second) < std::min(y.first, y.second);
            });

    // (flipped or not, parity of number of flips so far)
    std::vector<std::vector<int>> dp(2, std::vector<int>(2, 0));
    dp[0][0] = 1;
    dp[1][1] = 1;
    for(int i = 1; i < N; i++) {
        std::vector<std::vector<int>> ndp(2, std::vector<int>(2, 0));
        if(A[i].first > A[i - 1].first && A[i].second > A[i - 1].second) {
            ndp[0][0] = ndp[0][0] || dp[0][0];
            ndp[0][1] = ndp[0][1] || dp[0][1];

            ndp[1][0] = ndp[1][0] || dp[1][1];
            ndp[1][1] = ndp[1][1] || dp[1][0];
        } 

        if(A[i].first > A[i - 1].second && A[i].second > A[i - 1].first) {
            ndp[0][0] = ndp[0][0] || dp[1][0];
            ndp[0][1] = ndp[0][1] || dp[1][1];
        }

        if(A[i].second > A[i - 1].first && A[i].first > A[i - 1].second) {
            ndp[1][0] = ndp[1][0] || dp[0][1];
            ndp[1][1] = ndp[1][1] || dp[0][0];
        }

        std::swap(dp, ndp);
    }

    for(int i = 0; i < 2; i++) {
        if(dp[i][0]) {
            std::cout << "Yes" << '\n';
            return;
        }
    }

    std::cout << "No" << '\n';
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
