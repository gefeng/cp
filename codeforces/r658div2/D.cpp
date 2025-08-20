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

    int n = N << 1;
    std::vector<int> A(n);
    for(int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    std::vector<int> nxt_greater(n, n);
    std::vector<int> stk;
    for(int i = n - 1; i >= 0; i--) {
        while(!stk.empty() && A[stk.back()] < A[i]) {
            stk.pop_back();
        }

        nxt_greater[i] = stk.empty() ? n : stk.back();
        stk.push_back(i);
    }
        
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= n; j++) {
            if(!dp[i][j]) {
                continue;
            }
            
            int k = nxt_greater[i];
            dp[k][j + k - i] = 1;
            dp[k][j] = 1;
        }
    }

    std::cout << (dp[n][N] ? "YES" : "NO") << '\n';
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
