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
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    std::vector<int> freq;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i += 1;
        }

        freq.push_back(i - j);
    }

    
    int n = freq.size();
    int ans = n;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, -INF));
    dp[1][0] = 1;
    
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            if(dp[i - 1][j] != -INF) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + 1);
            }
            
            if(j - 1 >= 0 && dp[i - 1][j - 1] != -INF && dp[i - 1][j - 1] - freq[i - 1] >= 0) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] - freq[i - 1]);
            }
        }
    }

    for(int i = n - 1; i >= 0; i--) {
        if(dp[n][i] >= 0) {
            ans = n - i;
            break;
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
