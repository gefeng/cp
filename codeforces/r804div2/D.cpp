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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> removable(N, std::vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        std::vector<int> freq(N + 1, 0);
        int max_f = 0;
        for(int j = i; j < N; j++) {
            freq[A[j]] += 1; 
            max_f = std::max(max_f, freq[A[j]]);

            removable[i][j] = (max_f <= (j - i + 1) / 2 && (j - i + 1) % 2 == 0);
        }
    }

    int ans = 0;
    std::vector<int> dp(N, -1);
    for(int i = 0; i < N; i++) {
        if(i == 0 || removable[0][i - 1]) {
            dp[i] = 1;
        }
        for(int j = i - 1; j >= 0; j--) {
            if(A[j] == A[i] && dp[j] != -1 && (i == j + 1 || removable[j + 1][i - 1])) {
                dp[i] = std::max(dp[i], dp[j] + 1); 
            }
        }
        if(dp[i] != -1 && (i == N - 1 || removable[i + 1][N - 1])) {
            ans = std::max(ans, dp[i]);
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
