#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

int64_t dfs(int64_t N, std::map<int64_t, int64_t>& dp) {
    if(N < 2) {
        return 0;
    }  

    if(dp.find(N) != dp.end()) {
        return dp[N];
    }

    int64_t res = dfs(N / 2, dp) + dfs((N + 1) / 2, dp) + N;
    dp[N] = res;
    
    return res;
}

void run_case() {
    int64_t N;
    std::cin >> N;

    std::map<int64_t, int64_t> dp;
    std::cout << dfs(N, dp) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
