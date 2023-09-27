#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <queue>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int, int> freq;
    int max_v = 0;
    for(int x : A) {
        freq[x] += 1;
        max_v = std::max(max_v, x);
    }

    std::vector<int> dp(max_v + 1, 0);
    for(int i = max_v; i > 0; i--) {
        if(freq.find(i) == freq.end()) {
            continue;
        }

        dp[i] = std::max(dp[i], freq[i]);
        for(int j = i + i; j <= max_v; j += i) {
            if(dp[j] != 0) {
                dp[i] = std::max(dp[i], dp[j] + freq[i]);
            }
        }
    }

    int64_t ans = 0;
    for(int i = 1; i <= max_v; i++) {
        ans = std::max(ans, (int64_t)dp[i] * i);
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
