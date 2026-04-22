#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int>(2e9) + 10;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::string> A(2);
    for(int i = 0; i < 2; i++) {
        std::cin >> A[i];
    }

    std::vector<int> dp(N + 1, INF);
    dp[0] = 0;
    
    // B R B R
    // B R R B
    std::array<char, 4> R1 = {'B', 'R', 'B', 'R'};
    std::array<char, 4> R2 = {'B', 'R', 'R', 'B'};

    auto get_cost2 = [&](int from, int to) {
        int cost = 0;
        
        if(A[0][from] != R1[to]) {
            cost++;
        }
        if(A[1][from] != R2[to]) {
            cost++;
        }
        return cost;
    };

    auto get_cost4 = [&](int s1, int s2, int t1, int t2) {
        return get_cost2(s1, t1) + get_cost2(s2, t2);
    };

    dp[1] = std::min(get_cost2(0, 0), get_cost2(0, 1));

    for(int i = 2; i <= N; i++) {
        dp[i] = std::min(dp[i], dp[i - 1] + std::min(get_cost2(i - 1, 0), get_cost2(i - 1, 1)));
        dp[i] = std::min(dp[i], dp[i - 2] + get_cost4(i - 2, i - 1, 0, 0));
        dp[i] = std::min(dp[i], dp[i - 2] + get_cost4(i - 2, i - 1, 1, 1));
        dp[i] = std::min(dp[i], dp[i - 2] + get_cost4(i - 2, i - 1, 2, 2));
        dp[i] = std::min(dp[i], dp[i - 2] + get_cost4(i - 2, i - 1, 3, 3));
        dp[i] = std::min(dp[i], dp[i - 2] + get_cost4(i - 2, i - 1, 0, 1));
        dp[i] = std::min(dp[i], dp[i - 2] + get_cost4(i - 2, i - 1, 1, 0));
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
