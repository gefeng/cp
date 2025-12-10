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
    }

    std::ranges::sort(A);
    
    std::vector<std::pair<int, int>> a;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i += 1;
        }
        a.emplace_back(A[j], i - j);
    }

    auto valid = [](int x, int y) {
        return (x ^ y) == y - x;
    };

    int n = a.size();
    std::vector<int> dp(n, 0);

    int ans = 0;
    for(int i = 0; i < n; i++) {
        dp[i] = a[i].second;
        
        for(int j = i - 1; j >= 0; j--) {
            if(valid(a[j].first, a[i].first)) {
                dp[i] = std::max(dp[i], dp[j] + a[i].second);
            }
        }

        ans = std::max(ans, dp[i]);
    }

    std::cout << ans << '\n';
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
