#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = int(1e6);

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    std::vector<int> freq(MAX + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        freq[A[i]] += 1;
    }

    std::vector<int> ds(MAX + 1, 0);
    std::vector<int> dp(MAX + 1, 0);
    for(int i = 1; i <= MAX; i++) {
        ds[i] = freq[i];
        for(int j = i + i; j <= MAX; j += i) {
            ds[i] += freq[j];
        } 
    }

    for(int i = 1; i <= MAX; i++) {
        if(ds[i] >= K) {
            dp[i] = i;
        }
        for(int j = i + i; j <= MAX; j += i) {
            dp[j] = std::max(dp[j], dp[i]);
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << (dp[A[i]] == 0 ? 1 : dp[A[i]]) << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
