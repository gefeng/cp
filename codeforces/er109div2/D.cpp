#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> a;
    for(int i = 0; i < N; i++) {
        if(A[i]) {
            a.push_back(i);
        }
    }

    if(a.empty()) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<int> dp(N, INF);
    std::vector<int> ds(N, INF);
    int n = a.size();
    for(int i = 0; i < N; i++) {
        if(!A[i]) {
            dp[i] = std::abs(i - a[0]);
        }
        ds[i] = i == 0 ? dp[0] : std::min(ds[i - 1], dp[i]);
    }

    for(int i = 1; i < n; i++) {
        std::vector<int> ndp(N, INF);
        for(int j = 0; j < N; j++) {
            if(!A[j]) {
                int min_v = j == 0 ? INF : ds[j - 1];
                if(min_v != INF) {
                    ndp[j] = std::min(ndp[j], min_v + std::abs(a[i] - j));
                }
            }
        }

        std::swap(dp, ndp);
        for(int j = 0; j < N; j++) {
            ds[j] = j == 0 ? dp[0] : std::min(ds[j - 1], dp[j]);
        }
    }

    int ans = *std::min_element(dp.begin(), dp.end());
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
