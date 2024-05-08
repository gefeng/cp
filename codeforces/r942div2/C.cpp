#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = int64_t(1e13);

void run_case() {
    int N;
    int64_t K;
    std::cin >> N >> K;

    std::vector<int64_t> A(N);
    int64_t min_v = MAX;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        min_v = std::min(min_v, A[i]);
    }

    int64_t lo = min_v;
    int64_t hi = MAX;
    int64_t ans = 0;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        
        int64_t cnt = 0;
        int64_t cnt_greater = 0;
        for(int i = 0; i < N; i++) {
            cnt += std::max(mid - A[i], int64_t(0));
            if(A[i] > mid) {
                cnt_greater += 1;
            }
        }

        if(cnt <= K) {
            ans = std::max(ans, mid * N - N + 1 + cnt_greater + K - cnt); 
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
