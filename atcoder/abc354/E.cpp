#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int dfs(int N, std::vector<int>& A, std::vector<int>& B, int used, std::vector<int>& dp) {
    if(used == (1 << N) - 1) {
        return 0;
    }

    if(dp[used] != -1) {
        return dp[used];
    }

    int res = 0;
    if(__builtin_popcount(used) == 1) {
        res = 0;
    } else {
        for(int i = 0; i < N; i++) {
            if(!(used & (1 << i))) {
                for(int j = 0; j < N; j++) {
                    if(j != i && !(used & (1 << j)) && (A[i] == A[j] || B[i] == B[j])) {
                        int ret = dfs(N, A, B, (used | 1 << i) | (1 << j), dp); 
                        if(ret == 0) {
                            res = 1;
                        }
                    }
                }
            }
        }
    }

    return dp[used] = res;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i];
    }

    std::vector<int> dp(1 << N, -1);
    std::cout << (dfs(N, A, B, 0, dp) ? "Takahashi" : "Aoki") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
