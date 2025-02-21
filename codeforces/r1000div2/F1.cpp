#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int64_t MOD = int64_t(998244353);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int64_t>> dp(N * 2 + 1, std::vector<int64_t>(N + 1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= N * 2; i++) {
        for(int j = 0; j <= N; j++) {
            if(j + 1 <= N) {
                dp[i][j + 1] += dp[i - 1][j];
                dp[i][j + 1] %= MOD;
            }
            if(j - 1 >= 0) {
                dp[i][j - 1] += dp[i - 1][j];
                dp[i][j - 1] %= MOD;
            }
        }
    }

    std::cout << dp[N * 2][0] << ' ';

    std::string s(N << 1, '.');
    for(int i = 0; i < N; i++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;
        
        s[L] = '(';  
        s[R] = ')'; 
    
        std::string stk;
        int64_t res = 1;
        for(char c : s) {
            if(c == ')') {
                int cnt = 0;
                while(stk.back() != '(') {
                    cnt += 1;
                    stk.pop_back();
                } 
                stk.pop_back(); 
                res *= dp[cnt][0];
                res %= MOD;
            } else {
                stk.push_back(c);
            }
        }

        if(!stk.empty()) {
            res *= dp[stk.size()][0];
            res %= MOD;
        }

        std::cout << res << " \n"[i == N - 1];
    }
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
