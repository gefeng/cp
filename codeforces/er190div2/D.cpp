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
    std::vector<int> B(N);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int64_t ans = 0;
    std::vector<int64_t> dp(N, 0);
    std::vector<int> nxta(N + 1, N);
    std::vector<int> nxtb(N + 1, N);
    std::vector<int> sa(N + 2, N);
    std::vector<int> sb(N + 2, N);
    for(int i = N - 1; i >= 0; i--) {
        nxta[i] = sa[A[i] + 1];
        nxtb[i] = sb[B[i] + 1];
        sa[A[i]] = i;
        sb[B[i]] = i;
    }

    for(int i = N - 1; i >= 0; i--) {
        if(A[i] == B[i]) {
            int pa = nxta[i];
            int pb = nxtb[i];
            if(pa == pb) {
                dp[i] = pa == N ? N : dp[pa];
            } else {
                dp[i] = std::min(pa, pb);
            }
        }
    }
        
    int onea = N;
    int oneb = N;
    for(int i = N - 1; i >= 0; i--) {
        if(A[i] == 1) {
            onea = i;
        }
        if(B[i] == 1) {
            oneb = i;
        }
        if(A[i] == B[i] && A[i] == 1) {
            ans += dp[i] - i;
        } else {
            if(onea == oneb) {
                ans += onea == N ? N - i : dp[onea] - i;
            } else {
                ans += std::min(onea, oneb) - i;
            }
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
