#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int N;
    int64_t X, Y;
    std::cin >> N >> X >> Y;

    std::string S, T;
    std::cin >> S >> T;

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] != T[i]) {
            cnt += 1;
        }
    }

    if(cnt % 2 == 1) {
        std::cout << -1 << '\n';
        return;
    }

    if(Y <= X) {
        if(cnt > 2) {
            std::cout << Y * (cnt / 2) << '\n';
            return;
        }

        int pre = -1;
        for(int i = 0; i < N; i++) {
            if(S[i] != T[i]) {
                if(pre != -1) {
                    if(pre + 1 == i) {
                        std::cout << std::min(X, Y * 2) << '\n';
                    } else {
                        std::cout << Y << '\n';
                    }
                    return;
                }
                pre = i;
            }
        }
        std::cout << 0 << '\n';
        return;
    }

    std::vector<int> a;
    for(int i = 0; i < N; i++) {
        if(S[i] != T[i]) {
            a.push_back(i);
        }
    }

    int size = a.size();
    std::vector<int64_t> cost(size + 1, 0);
    for(int i = 2; i <= size; i++) {
        cost[i] = cost[i - 2] + (a[i - 1] - a[i - 2]) * X;
    }

    std::vector<int64_t> dp(size + 1, INF);
    dp[0] = 0;
    
    int64_t min_v = 0;
    for(int i = 1; i <= size; i++) {
        if(i % 2 == 1) {
            continue;
        }

        dp[i] = std::min(dp[i], dp[i - 2] + std::min(Y, (a[i - 1] - a[i - 2]) * X));

        for(int j = i - 2; j >= 0; j -= 2) {
            dp[i] = std::min(dp[i], dp[j] + Y + cost[i - 1] - cost[j + 1]);
        }
    }

    std::cout << dp[size] << '\n';
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
