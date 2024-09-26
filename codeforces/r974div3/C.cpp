#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = int64_t(2e18);

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum += A[i];
    }

    int max_v = *std::max_element(A.begin(), A.end());

    int64_t lo = 0;
    int64_t hi = MAX;
    int64_t ans = -1;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        
        int cnt = 0;
        int take = 0;
        for(int i = 0; i < N; i++) {
            int64_t x = A[i];
            if(x == max_v && !take) {
                x = max_v + mid;
                take = 1;
            }
            if(int64_t(N) * 2 * x < sum + mid) {
                cnt += 1;
            }
        }

        if(cnt > N / 2) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
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
