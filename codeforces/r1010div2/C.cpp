#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;

int64_t rev_2 = 0;

int64_t q_pow(int64_t x, int64_t y) {
    int64_t res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

int64_t dfs(std::string& S, int p, int flip, std::vector<std::vector<int64_t>>& dp) {
    if(p == 0) {
        return 0;
    }

    if(dp[flip][p] != -1) {
        return dp[flip][p];
    }

    int64_t res = 0;    
    int b = S[p] - '0';
    b ^= flip;
    if(b == 0) {
        int np = p;
        for(int i = p - 1; i >= 0; i--) {
            if(S[i] == '0') {
                continue;
            }
            np = i;
            break;
        }
        res += dfs(S, np, 0, dp) + p - np;
        res %= MOD;
    } else {
        res += (dfs(S, p - 1, 0, dp) + 1) * rev_2 % MOD;
        res %= MOD;
        
        int np = p;
        for(int i = p - 1; i >= 0; i--) {
            if(S[i] == '1') {
                np = i;
            } else {
                break;
            }
        }
        if(np == 0) {
            res += (p - np + 1) * rev_2 % MOD;
            res %= MOD;
        } else {
            res += (dfs(S, np - 1, 1, dp) + p - np + 1) * rev_2 % MOD;
            res %= MOD;
        }
    }

    return dp[flip][p] = res;
}

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;
    
    std::vector<std::vector<int64_t>> dp(2, std::vector<int64_t>(N, -1));
    std::cout << dfs(S, N - 1, 0, dp) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    rev_2 = q_pow(2, MOD - 2);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
