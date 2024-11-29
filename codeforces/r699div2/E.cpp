#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    std::vector<int> c_l(N, -1);
    std::vector<int> c_r(N, -1);
    for(int i = 0; i < N; i++) {
        if(c_l[A[i]] == -1) {
            c_l[A[i]] = i;
        }
        c_r[A[i]] = i;
    }

    std::vector<int> freq(N, 0);
    std::vector<int> dp(N, 0);
    dp[N - 1] = 1;
    freq[A.back()] += 1;
    
    for(int i = N - 2; i >= 0; i--) {
        freq[A[i]] += 1;
        dp[i] = dp[i + 1];
        if(c_l[A[i]] == i) {
            dp[i] = std::max(dp[i], freq[A[i]] + (c_r[A[i]] == N - 1 ? 0 : dp[c_r[A[i]] + 1]));
        } else {
            dp[i] = std::max(dp[i], freq[A[i]]);
        }
    }

    std::cout << N - dp[0] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
