#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int64_t MOD = (int64_t)1e9 + 7;

std::vector<std::vector<std::array<int64_t, 3>>> dp;

std::array<int64_t, 3> dfs(int n, int k) {
    if(dp[n][k][2] != -1) {
        return dp[n][k];
    }

    if(n == 0) {
        return dp[n][k] = {1, 1, 1}; 
    }
    
    if(k == 0) {
        return dp[n][k] = {1, 0, 1};
    }

    std::array<int64_t, 3> x = dfs(n - 1, k);
    std::array<int64_t, 3> y = dfs(n - 1, k - 1);
    
    std::array<int64_t, 3> res = {};
    
    res[0] = x[0] == x[1] ? (x[0] + y[0]) % MOD : x[0];
    res[1] = y[0] == y[1] ? (y[1] + x[1]) % MOD : y[1];
    res[2] = (((x[2] + y[2]) % MOD) + (x[1] * y[0] % MOD)) % MOD;

    return dp[n][k] = res;
}

void run_case() {
    int64_t N;
    int K;
    std::cin >> N >> K;
     
    std::array<int64_t, 3> a = {-1, -1, -1};
    while(N && K >= 0) {
        int m = 0;
        int64_t p2 = 1;
        
        while(p2 <= N) {
            p2 *= 2;
            m += 1;
        }

        p2 /= 2;
        m -= 1;

        if(a[0] == -1) {
            a = dp[m][K];
        } else {
            std::array<int64_t, 3> b = dp[m][K];
            std::array<int64_t, 3> na = {};
            na[0] = a[0] == a[1] ? (a[0] + b[0]) % MOD : a[0];
            na[1] = b[0] == b[1] ? (b[1] + a[1]) % MOD : b[1];
            na[2] = (((a[2] + b[2]) % MOD) + (a[1] * b[0] % MOD)) % MOD;
            std::swap(a, na);
        } 
            
        N -= p2;
        K -= 1;
    }

    std::cout << a[2] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    dp = std::vector<std::vector<std::array<int64_t, 3>>>(61, std::vector<std::array<int64_t, 3>>(61, {-1, -1, -1}));
    for(int i = 0; i <= 60; i++) {
        for(int j = 0; j <= 60; j++) {
            if(dp[i][j][0] == -1) {
                dfs(i, j);
            }
        }
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
