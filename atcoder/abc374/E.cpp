#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = int(2e9);
constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int N, X;
    std::cin >> N >> X;
    
    std::vector<std::array<int, 4>> A(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 4; j++) {
            std::cin >> A[i][j];
        }
    }

    int64_t lo = 0;
    int64_t hi = MAX;
    int64_t ans = 0; 
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        
        int64_t tot = 0;
        for(int i = 0; i < N; i++) {
            int64_t cost = INF; 
            for(int64_t a = 0; a <= A[i][2]; a++) {
                int64_t rem = std::max(int64_t(0), mid - a * A[i][0]);
                cost = std::min(cost, a * A[i][1] + (rem + A[i][2] - 1) / A[i][2] * A[i][3]);
            }
            
            for(int b = 0; b <= A[i][0]; b++) {
                int64_t rem = std::max(int64_t(0), mid - b * A[i][2]);
                cost = std::min(cost, b * A[i][3] + (rem + A[i][0] - 1) / A[i][0] * A[i][1]);
            }

            tot += cost;
        }

        if(tot <= X) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
