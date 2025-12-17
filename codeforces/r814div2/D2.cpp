#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int MAX = 10000;
constexpr int INF = static_cast<int>(2e9) + 10;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> dp(N + 1, 0);
    std::map<int, int> m;
    int sum = 0;

    m[0] = 0;
    for(int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1] + (A[i - 1] == 0 ? 0 : 1);
        sum ^= A[i - 1];
        if(m.find(sum) != m.end()) {
            int j = m[sum];
            dp[i] = std::min(dp[i], dp[j] + i - j - 1);
        }
        m[sum] = i;
    }

    std::cout << dp[N] << '\n';
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
