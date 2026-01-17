#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int dfs(std::string& S, int l, int r, int c, std::vector<std::vector<std::vector<int>>>& dp) {
    if(l > r) {
        return 1;
    }
    
    if(dp[c][l][r] != -1) {
        return dp[c][l][r];
    }

    if((r - l) % 2 == 1) {
        int pick_l = dfs(S, l + 1, r, S[l] - 'a', dp);
        int pick_r = dfs(S, l, r - 1, S[r] - 'a', dp);
        return dp[c][l][r] = (!pick_l || !pick_r) ? 0 : 1;
    } else {
        int pick_l = 0;
        int pick_r = 0;
        if(S[l] - 'a' == c) {
            pick_l = dfs(S, l + 1, r, S[l] - 'a', dp); 
        }
        if(S[r] - 'a' == c && l < r) {
            pick_r = dfs(S, l, r - 1, S[r] - 'a', dp);
        }
        return dp[c][l][r] = pick_l || pick_r;
    }
}

void run_case() {
    std::string S;
    std::cin >> S;

    int n = S.size();
    std::vector<std::vector<std::vector<int>>> dp(26, std::vector<std::vector<int>>(n, std::vector<int>(n, -1)));
    
    int ans = dfs(S, 0, n - 1, 0, dp);
    std::cout << (!ans ? "Alice" : "Draw") << '\n';
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
