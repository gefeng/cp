#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

int dfs(std::vector<int>& a, int now, int c, int k, std::vector<std::vector<std::vector<int>>>& dp) {
    if(now == 0) {
        int cnt = 0;
        int b = a[now];
        if(b) {
            cnt = c ? k + 1 : k;
        } else {
            cnt = c ? k : std::max(0, k - 1);
        }
        return cnt;
    }

    if(dp[c][k][now] != -1) {
        return dp[c][k][now];
    }

    int res = 0;
    int b = a[now];
    if(b) {
        if(c) {
            res = std::max(res, dfs(a, now - 1, c, k, dp) + 1);
        } else {
            res = std::max(res, dfs(a, now - 1, 0, k, dp));
            if(k) {
                res = std::max(res, dfs(a, now - 1, 1, k - 1, dp) + 1);
            }
        }
    } else {
        if(c) {
            res = std::max(res, dfs(a, now - 1, 0, k, dp));
            if(k) {
                res = std::max(res, dfs(a, now - 1, 1, k - 1, dp) + 1);
            }
        } else {
            res = std::max(res, dfs(a, now - 1, 0, k, dp));
            if(k > 1) {
                res = std::max(res, dfs(a, now - 1, 1, k - 2, dp) + 1);
            }
        }
    }
    
    return dp[c][k][now] = res;
}

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    int hb = -1;
    int lb = -1;
    for(int i = 30; i >= 0; i--) {
        if(N & (1 << i)) {
            hb = hb == -1 ? i : hb;
            lb = i;
        }
    }

    int cnt = 0;
    for(int i = lb; i <= hb; i++) {
        if(!(N & (1 << i))) {
           cnt += 1;
        }
    }
    cnt += 1;

    int ans = 0;
    if(cnt <= K) {
        ans = K - cnt + (hb - lb + 1);
    } else {
        std::vector<int> a;
        for(int i = hb; i >= lb; i--) {
            a.push_back((N & (1 << i)) ? 1 : 0);
        }

        int n = a.size();
        std::vector<std::vector<std::vector<int>>> dp(2, std::vector<std::vector<int>>(K + 1, std::vector<int>(n, -1)));
        
        ans = dfs(a, n - 1, 0, K, dp);
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
