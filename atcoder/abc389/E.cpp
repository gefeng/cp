#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = int64_t(1e9);

void run_case() {
    int N;
    int64_t M;
    std::cin >> N >> M;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t lo = 0;
    int64_t hi = M;
    int64_t ans = 0;

    while(lo <= hi) {
        int64_t mid = lo + (hi - lo) / 2;
        int64_t tot = M;
        int64_t cnt = 0; 
         
        bool ok = true;
        for(int i = 0; i < N; i++) {
            int64_t buy = ((mid - 1) / A[i] + 1) / 2;

            if(buy == 0) {
                continue;
            }
            
            if(buy <= MAX && buy * buy <= tot / A[i]) {
                tot -= buy * buy * A[i]; 
                cnt += buy;
            } else {
                ok = false;
                break;
            }
        }

        if(ok) {
            ans = cnt + tot / mid;
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
