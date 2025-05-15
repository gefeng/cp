#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N, K, X;
    std::cin >> N >> K >> X;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] + A[i];
    }

    int64_t lo = 0;
    int64_t hi = N * K - 1;
    int64_t ans = -1;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        
        int64_t sum = ((N * K - mid) / N) * psum[N];
        if(mid % N != 0) {
            sum += psum[N] - psum[mid % N];
        }
        if(sum >= X) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    std::cout << (ans == -1 ? 0 : ans + 1) << '\n';
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
