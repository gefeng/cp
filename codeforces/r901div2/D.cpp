#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)1e18;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    
    if(A.front()) {
        std::cout << 0 << '\n';
        return;
    }

    int mex = 0;
    int cnt_zero = 0;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i += 1;
        }

        if(A[j] == 0) {
            cnt_zero = i - j;
        }

        if(A[j] == mex) {
            mex += 1;
        } else {
            break;
        }
    }

    std::vector<std::pair<int, int>> a;
    for(int i = 0; i < N; ) {
        if(A[i] > mex) {
            break;
        } 

        int j = i;
        while(i < N && A[i] == A[j]) {
            i += 1;
        }

        if(A[j]) {
            a.emplace_back(A[j], i - j);
        }
    }

    int sz = a.size();
    std::vector<std::vector<int64_t>> dp(sz + 1, std::vector<int64_t>(mex + 1, INF));
    dp[0][mex] = 0;
    for(int i = 1; i <= sz; i++) {
        int v = a[sz - i].first;
        int f = a[sz - i].second;
        
        for(int j = 0; j <= mex; j++) {
            dp[i][j] = dp[i - 1][j];
        } 

        for(int j = v + 1; j <= mex; j++) {
            if(dp[i - 1][j] != INF) {
                int64_t cost = (int64_t)j * (f - 1) + v;
                dp[i][v] = std::min(dp[i][v], dp[i - 1][j] + cost);
            }            
        }
    }

    int64_t ans = INF;
    for(int i = 0; i <= mex; i++) {
        if(dp[sz][i] != INF) {
            ans = std::min(ans, dp[sz][i] + (int64_t)i * (cnt_zero - 1));
        }
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
