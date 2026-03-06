#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(998244353);

std::vector<int> prefix_function(std::vector<int> a) {
    int n = (int)a.size();
    std::vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && a[i] != a[j])
            j = pi[j-1];
        if (a[i] == a[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> f(N);
    for(int i = 0; i < N; i++) {
        std::vector<int> a(A.begin() + i, A.end());
        f[i] = prefix_function(a);
    }

    std::vector<int64_t> dp(N + 1, 0);
    dp[0] = 1;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < i; j++) {
            if(f[j][i - 1 - j] == 0) {
                dp[i] += dp[j];
                dp[i] %= MOD;
            }
        }
    }

    std::cout << dp[N] << '\n';
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
