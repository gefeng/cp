#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int dfs(std::vector<int>& a, int i, int stay, std::vector<std::vector<int>>& dp) {
    if(i == a.size() - 1) {
        return 1;
    }

    if(dp[stay][i] != -1) {
        return dp[stay][i];
    }

    int res = 0;
    if(stay) {
        if(dfs(a, i + 1, 0, dp) == 0) {
            res = 1;
        }
    } else {
        int v = i == 0 ? a[i] : a[i] - a[i - 1]; 
        if(v == 1) {
            if(dfs(a, i + 1, 0, dp) == 0) {
                res = 1;
            }
        } else {
            if(dfs(a, i + 1, 0, dp) == 0 || dfs(a, i, 1, dp) == 0) {
                res = 1;
            }
        }
    }

    return dp[stay][i] = res;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    
    A.erase(std::unique(A.begin(), A.end()), A.end());

    std::vector<std::vector<int>> dp(2, std::vector<int>(A.size(), -1));
    std::cout << (dfs(A, 0, 0, dp) ? "Alice" : "Bob") << '\n';
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
