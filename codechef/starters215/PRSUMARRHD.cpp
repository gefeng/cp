#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

int64_t dfs(std::vector<int>& factors, std::map<int, int>& m, int t, int ub, std::vector<std::vector<int64_t>>& dp) {
    if(t == 0) {
        return 1;
    }
    if(dp[t][ub] != -1) {
        return dp[t][ub];
    }

    int64_t res = 0;

    int x = factors[t];
    for(int i = 1; i <= ub; i++) {
        if(x % factors[i] == 0) {
            res += dfs(factors, m, m[x / factors[i]], i, dp);
        }
    }
    
    return dp[t][ub] = res;
}

void run_case() {
    int N;
    std::cin >> N;

    if(N <= 3) {
        std::cout << 1 << '\n';
        return;
    }

    std::vector<int> factors;
    int64_t ans = 0;
    for(int i = 1; i * i <= N; i++) {
        if(N % i == 0) {
            factors.push_back(i);
            if(N / i != i) {
                factors.push_back(N / i);
            }
        }
    }

    int n = factors.size();
    std::ranges::sort(factors);
    if(n == 0) {
        std::cout << 1 << '\n';
        return;
    }
    
    std::map<int, int> m;
    for(int i = 0; i < n; i++) {
        m[factors[i]] = i;
    }
    
    std::vector<std::vector<int64_t>> dp(n, std::vector<int64_t>(n, -1));
    ans += dfs(factors, m, n - 1, n - 1, dp);

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
