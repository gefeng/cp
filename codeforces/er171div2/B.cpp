#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(N == 1) {
        std::cout << 1 << '\n';
        return;
    }

    int64_t ans = INF;
    if(N % 2 == 0) {
        ans = 0;
        for(int i = 0; i < N; i += 2) {
            ans = std::max(ans, A[i + 1] - A[i]);
        } 
    } else {
        for(int i = 0; i < N; i++) {
            if(i % 2 == 0) {
                int64_t cand = 0;
                for(int j = 0; j < i; j += 2) {
                    cand = std::max(cand, A[j + 1] - A[j]); 
                }
                for(int j = i + 1; j < N; j += 2) {
                    cand = std::max(cand, A[j + 1] - A[j]);
                }
                ans = std::min(ans, cand);
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
