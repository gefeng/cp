#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = 2e18;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + A[i - 1];
    }

    auto perf = [&](int64_t k, int64_t u) {
        return k * u - k * (k - 1) / 2; 
    };

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int L, U;
        std::cin >> L >> U;
        L -= 1;
        
        int lo = L;
        int hi = N - 1;
        while(hi - lo >= 3) {
            int m1 = lo + (hi - lo) / 3;
            int m2 = hi - (hi - lo) / 3;
            
            int64_t k1 = psum[m1 + 1] - psum[L];
            int64_t k2 = psum[m2 + 1] - psum[L];
            
            int64_t f1 = perf(k1, U);
            int64_t f2 = perf(k2, U);
            
            if(f1 < f2) {
                lo = m1;
            } else {
                hi = m2;
            }
        }

        int64_t max_p = -INF;
        int res = -1;
        for(int j = lo; j <= hi; j++) {
            int64_t k = psum[j + 1] - psum[L];
            int64_t f = perf(k, U);
            if(f > max_p) {
                max_p = f;
                res = j;
            }
        }
        std::cout << res + 1 << " \n"[i == Q - 1];
    }
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
