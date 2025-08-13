#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int>(2e9);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> dp(N, INF);
    std::vector<int> stk1;
    std::vector<int> stk2;
    std::vector<int> nxt_s(N, N);
    std::vector<int> nxt_g(N, N);
    for(int i = N - 1; i >= 0; i--) {
        while(!stk1.empty() && A[stk1.back()] < A[i]) {
            stk1.pop_back();
        }
        while(!stk2.empty() && A[stk2.back()] > A[i]) {
            stk2.pop_back();
        }
        
        if(!stk1.empty()) {
            nxt_g[i] = stk1.back();
        }
        if(!stk2.empty()) {
            nxt_s[i] = stk2.back();
        }

        stk1.push_back(i);
        stk2.push_back(i);
    }
    
    stk1.clear();
    stk2.clear();
    dp[0] = 0;
    for(int i = 0; i < N; i++) {
        while(!stk1.empty() && A[stk1.back()] < A[i]) {
            stk1.pop_back();
        } 
        while(!stk2.empty() && A[stk2.back()] > A[i]) {
            stk2.pop_back();
        }

        if(i) {
            dp[i] = std::min(dp[i], dp[i - 1] + 1);
        }

        if(!stk1.empty()) {
            dp[i] = std::min(dp[i], dp[stk1.back()] + 1);
        }
        if(!stk2.empty()) {
            dp[i] = std::min(dp[i], dp[stk2.back()] + 1);
        }

        int j = nxt_s[i];
        if(j != N) {
            dp[j] = std::min(dp[j], dp[i] + 1);
        }
        j = nxt_g[i];
        if(j != N) {
            dp[j] = std::min(dp[j], dp[i] + 1);
        }

        stk1.push_back(i);
        stk2.push_back(i);
    }

    std::cout << dp[N - 1] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
