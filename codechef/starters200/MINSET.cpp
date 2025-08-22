#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

int64_t dfs(int l, int r, std::map<std::pair<int, int>, int64_t>& dp) {
    if(l >= r) {
        return 0;
    }
    if(r - l == 1) {
        return l ^ r;
    }

    if(dp.find({l, r}) != dp.end()) {
        return dp[{l, r}];
    }

    int p = 1;
    while(p * 2 <= r) {
        p *= 2;
    }

    int64_t cost = 0;
    if(l == 1) {
        cost = p == r ? p + 1 : p;
        cost += dfs(l, p - 1, dp);
        cost += dfs(0, r - p, dp);
    } else {
        cost = p; 
        cost += dfs(l, p - 1, dp);
        cost += dfs(0, r - p, dp);
    }
    return dp[{l, r}] = cost;
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::map<std::pair<int, int>, int64_t> dp;
    int64_t ans = dfs(1, N, dp);
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
