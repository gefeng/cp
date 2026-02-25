#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int INF = static_cast<int>(2e9) + 10;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int min_v = INF;
    std::vector<int> head(N, -1);
    std::vector<int> pre(N, -1);
    for(int i = 0; i < N; i++) {
        min_v = A[i];
        int j = i;
        while(i + 1 < N) {
            if(A[i + 1] <= min_v) {
                break;
            }
            if((A[i + 1] - 1 == A[i]) || A[i + 1] <= A[i]) {
                i += 1;
            } else {
                break;
            }
        }
    
        head[j] = j;
        std::map<int, int> m;
        m[A[j]] = j;
        for(int k = j + 1; k <= i; k++) {
            head[k] = j; 
            pre[k] = m[A[k] - 1];
            m[A[k]] = k;
        }
    }

    int64_t ans = 1;
    std::vector<int64_t> dp(N, 0);
    dp[0] = 1;
    for(int i = 1; i < N; i++) {
        if(head[i] == i) {
            dp[i] = dp[i - 1] + i + 1;
        } else {
            int j = pre[i];
            dp[i] = dp[i - 1] + i - j;
        }
        ans += dp[i];
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
