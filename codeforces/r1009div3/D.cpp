#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int64_t> C(N);
    std::vector<int64_t> R(N);
    for(int i = 0; i < N; i++) {
        std::cin >> C[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> R[i];
    } 

    std::map<int64_t, int64_t> m;
    for(int i = 0; i < N; i++) {
        for(int64_t x = C[i] - R[i]; x <= C[i] + R[i]; x++) {
            int64_t lo = 0;
            int64_t hi = R[i];
            int64_t res = 0;
            while(lo <= hi) {
                int64_t mid = (lo + hi) >> 1;
                
                if((x - C[i]) * (x - C[i]) + mid * mid <= R[i] * R[i]) {
                    res = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            m[x] = std::max(m[x], res);
        }
    }

    int64_t ans = 0;
    for(auto [x, y] : m) {
        ans += (y + 1) * 2 - 1; 
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
