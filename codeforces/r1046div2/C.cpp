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
    std::vector<std::vector<int>> pos(N + 1);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        pos[A[i]].push_back(i);
    }

    std::vector<int> pre(N, -1);
    for(int v = 1; v <= N; v++) {
        if(pos[v].empty()) {
            continue;
        }
        int size = pos[v].size();
        for(int i = v - 1; i < size; i++) {
            int p = pos[v][i];
            pre[p] = pos[v][i - v + 1];
        }
    }

    std::vector<int> dp(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1];
        int j = pre[i - 1];
        if(j != -1) {
            dp[i] = std::max(dp[i], dp[j] + A[i - 1]);
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
