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

    std::vector<int> dp(N + 1, 0);
    dp[0] = 1;
    
    for(int i = 0; i < N; i++) {
        int len = A[i];
        if(dp[i]) {
            if(i + len + 1 <= N) {
                dp[i + len + 1] = 1;
            }
        }
        
        if(i + 1 - len - 1 >= 0 && dp[i + 1 - len - 1]) {
            dp[i + 1] = 1;
        }
    }

    std::cout << (dp[N] ? "YES" : "NO") << '\n';
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
