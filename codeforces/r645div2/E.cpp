#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < (N + 1) / 2; i++) {
        std::cin >> A[i];
    }
    
    int X;
    std::cin >> X;
    for(int i = (N + 1) / 2; i < N; i++) {
        A[i] = X;
    }

    if(X >= 0) {
        int64_t sum = std::accumulate(A.begin(), A.end(), int64_t(0));
        std::cout << (sum <= 0 ? -1 : N) << '\n';
        return;
    }

    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] + A[i];
    }

    int lb = N / 2 + 1;
    for(int i = (N + 1) / 2 - 1; i >= 0; i--) {
        int lo = i + N / 2;
        int hi = N - 1;
        int j = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            if(psum[mid + 1] - psum[i] > 0) {
                j = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        if(j == -1 || j - i + 1 < lb) {
            lb = N - i + 1;
        }
    }

    std::cout << (lb > N ? -1 : lb) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
