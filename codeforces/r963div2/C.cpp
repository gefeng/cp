#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    int64_t l = A[0];
    int64_t r = A[0] + K - 1;
    int64_t f = K * 2;
    for(int i = 1; i < N; i++) {
        int64_t ll = A[i];
        int64_t rr = A[i] + K - 1;
        int64_t x1 = (ll - l + f - 1) / f;
        int64_t y1 = (rr - l) / f;
        
        int64_t x2 = ll - r < 0 ? 0 : (ll - r + f - 1) / f;
        int64_t y2 = (rr - r) / f;

        if(x1 <= y1 && x2 <= y2) {
            l = l + x1 * f;
            r = r + y2 * f;
        } else if(x1 <= y1) {
            l = l + x1 * f;
            r = rr;
        } else if(x2 <= y2) {
            l = ll;
            r = r + y2 * f;
        } else {
            std::cout << -1 << '\n';
            return;
        }
    }

    std::cout << l << '\n';
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
