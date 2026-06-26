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

    std::vector<int> dp(3, 0);
    int c1 = 0;
    int c0 = 0;
    int64_t ans = 0;
    int64_t bad = 0;
    dp[0] = 1;
    for(int i = 0; i < N; i++) {
        if(S[i] == '0') {
            c0++;
        } else {
            c1++;
        }
        
        int d = ((c0 % 3) - (c1 % 3) + 3) % 3;
        
        bad += dp[d];
        
        dp[d]++;
    }

    for(int i = 0; i < N; i++) {
        int j = i;
        while(i + 1 < N && S[i + 1] != S[i]) {
            i++;
        }
        int64_t len = i - j + 1;
        
        bad += ((len + 1) * (len + 1) / 2) / 2;
        bad -= len;
    }

    ans = static_cast<int64_t>(N) * (N + 1) / 2 - bad;
    
    std::cout << ans << '\n';
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
