#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)998244353;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> p2(N + 1, 1);
    for(int i = 1; i <= N; i++) {
        p2[i] = p2[i - 1] * 2 % MOD;
    }

    std::vector<int64_t> dp(N + 1, 0);
    std::vector<int> s;
    dp[0] = 1;
    for(int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1];

        int cnt = 0;
        while(!s.empty() && s.back() < A[i - 1]) {
            s.pop_back();
            cnt += 1;
        }

        if(cnt && s.empty()) {
            cnt -= 1;
        }

        s.push_back(A[i - 1]);
        dp[i] *= p2[cnt];
        dp[i] %= MOD;
        
        std::cout << dp[i] << " \n"[i == N];
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
