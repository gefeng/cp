#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> p2(N * 30 + 1, 1);
    for(int i = 1; i <= N * 30; i++) {
        p2[i] = p2[i - 1] * 2 % MOD;
    }
    
    std::vector<int64_t> psum(N + 1, 0);
    std::vector<int64_t> cnt2(N + 1, 0);
    for(int i = 0; i < N; i++) {
        int x = A[i];
        int cnt = 0;
        while(x % 2 == 0) {
            x /= 2;
            cnt += 1;
        }
        psum[i + 1] = (psum[i] + x) % MOD;
        cnt2[i + 1] = cnt2[i] + cnt;
    }

    auto less = [&](int j, int i) {
        int cnt = cnt2[i] - cnt2[j + 1];
        int64_t now = A[i];
        
        int t = A[j];
        while(t % 2 == 0) {
            t /= 2;
        }

        if(now > t) {
            return true;
        }

        for(int i = 0; i < cnt; i++) {
            now *= 2;
            if(now > t) {
                return true;
            }
        } 

        return false;
    };

    std::vector<int> pre(N, -1);
    std::vector<int> s;
    for(int i = 0; i < N; i++) {
        while(!s.empty() && less(s.back(), i)) {
            s.pop_back();
        }
        if(!s.empty()) {
            pre[i] = s.back();
        }
        s.push_back(i);
    }

    std::vector<int64_t> dp(N, 0);
    for(int i = 0; i < N; i++) {
        int j = pre[i]; 
        if(j == -1) {
            dp[i] = psum[i] + (A[i] * p2[cnt2[i]] % MOD);
            dp[i] %= MOD;
        } else {
            int cnt = cnt2[i] - cnt2[j + 1];
            dp[i] = dp[j];
            dp[i] += ((psum[i] - psum[j + 1] + MOD) % MOD);
            dp[i] %= MOD;
            dp[i] += A[i] * p2[cnt] % MOD;
            dp[i] %= MOD;
        }
        std::cout << dp[i] << " \n"[i == N - 1];
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
