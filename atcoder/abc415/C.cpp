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

    std::string S;
    std::cin >> S;

    std::vector<int> dp(1 << N, 0);
    dp[0] = 1;
    
    for(int mask = 0; mask < (1 << N); mask++) {
        if(!dp[mask]) {
            continue;
        }
        for(int i = 0; i < N; i++) {
            if(mask & (1 << i)) {
                continue;
            }
            
            int n_mask = mask | (1 << i);
            if(S[n_mask - 1] == '0') {
                dp[n_mask] = 1;
            }
        }
    }

    std::cout << (dp[(1 << N) - 1] ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
