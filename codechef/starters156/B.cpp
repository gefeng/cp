#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = int64_t(2e15);

void run_case() {
    int N, X;
    std::cin >> N >> X;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto is_overlap = [](int64_t l1, int64_t r1, int64_t l2, int64_t r2) {
        if(l1 > l2) {
            std::swap(l1, l2); 
            std::swap(r1, r2);
        }
        return l2 <= r1;
    };

    int64_t lo = 0;
    int64_t hi = MAX;
    int64_t min_d = -1;
    std::vector<int64_t> ans(N); 
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        
        bool ok = true;
        int64_t l = A[0] - mid;
        int64_t r = A[0] + mid + X;
        std::vector<int64_t> c(N); 
        c[0] = A[0] + mid;
        for(int i = 1; i < N; i++) {
            int64_t lx = A[i] - mid;
            int64_t rx = A[i] + mid;
            
            if(!is_overlap(l, r, lx, rx)) {
                ok = false;
                break;
            }

            l = std::max(l, lx);
            r = std::min(r, rx);
            c[i] = std::min(r, c[i - 1] + X);
            r += X;
        }

        if(ok) {
            min_d = mid;
            std::swap(ans, c);
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    std::cout << min_d << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
