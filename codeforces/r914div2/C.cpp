#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int64_t INF = (int64_t)3e18;

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(K > 2) {
        std::cout << 0 << '\n';
        return;
    }

    int64_t ans = INF;
    std::sort(A.begin(), A.end());
    ans = A[0];

    for(int i = 1; i < N; i++) {
        ans = std::min(ans, A[i] - A[i - 1]);
    }

    if(K == 2) {
        std::set<int64_t> s(A.begin(), A.end());
    
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                int64_t x = A[j] - A[i];
                
                auto it = s.lower_bound(x);
                if(it != s.end()) {
                    ans = std::min(ans, std::abs(*it - x)); 
                } 
                if(it != s.begin()) {
                    it--;
                    ans = std::min(ans, std::abs(*it - x));
                }
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
