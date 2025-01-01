#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    } 

    int64_t lo = 0;
    int64_t hi = int64_t(1e9);
    int64_t ans = -1;
    
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        
        bool good = true;
        int64_t r = mid;
        for(int i = 0; i < N; i++) {
            if(r > A[i]) {
                r = std::max(r, int64_t(A[i]) + B[i]) - 1;
            } else {
                r = r - 1 + B[i];
            }

            if(r < 0) {
                good = false;
                break;
            }
        }

        if(good) {
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
