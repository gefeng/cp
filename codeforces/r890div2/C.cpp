#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = 1e18;

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t lo = 1;
    int64_t hi = 1e9;
    int64_t ans = 0;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;

        int64_t min_steps = INF;
        for(int i = 0; i < N; i++) {
            int64_t x = mid;
            int64_t cnt = 0;
            for(int j = i; j < N; j++) {
                if(A[j] >= x) {
                    break;
                }

                if(j == N - 1 && A[j] < x) {
                    cnt = INF; 
                    break;
                }

                cnt += x - A[j]; 
                x -= 1;
            } 

            min_steps = std::min(min_steps, cnt);
        }

        if(min_steps <= K) {
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
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
