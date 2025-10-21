#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 5000;
constexpr int INF = int(2e9);

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    bool equal = true; 
    int g = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        if(A[i] != A[0]) {
            equal = false;
        }
        g = i == 0 ? A[0] : gcd(g, A[i]);
    }

    if(equal) {
        std::cout << 0 << '\n';
        return;
    }

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(g == A[i]) {
            cnt += 1;
        }
    }
    if(cnt) {
        std::cout << N - cnt << '\n';
        return;
    }

    std::vector<int> dp(MAX + 1, INF);
    for(int i = 0; i < N; i++) {
        std::vector<int> n_dp(dp);
        n_dp[A[i]] = 0;
        
        for(int j = g; j <= MAX; j++) {
            if(dp[j] != INF) {
                int x = gcd(j, A[i]);
                n_dp[x] = std::min(n_dp[x], dp[j] + 1);
            }
        }
        dp = std::move(n_dp);
    }

    std::cout << dp[g] + N - 1 << '\n';
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
