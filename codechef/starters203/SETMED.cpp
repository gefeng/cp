#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <numeric>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);

    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] + A[i];
    }

    int64_t sum = std::accumulate(A.begin(), A.end(), static_cast<int64_t>(0));
    int64_t ans = sum;

    for(int i = 0; i < N; i++) {
        int l = i;
        int r = N - 1 - i;
        
        if(l && r) {
            int lo = 1;
            int hi = std::min(l, r);
            int len = 0;
            while(lo <= hi) {
                int mid = (lo + hi) >> 1;
                
                if(A[mid - 1] + A[i + mid] < A[i] + A[i]) {
                    len = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            if(len) {
                ans = std::max(ans, 
                        sum - psum[len] - (psum[i + len + 1] - psum[i + 1]) + static_cast<int64_t>(A[i]) * len * 2);
            }
        }

        if(l && r > 1) {
            int lo = 1;
            int hi = std::min(l, r - 1);
            int len = 0;
            while(lo <= hi) {
                int mid = (lo + hi) >> 1;
                
                if(A[mid - 1] + A[i + 1 + mid] < A[i] + A[i]) {
                    len = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            if(len) {
                ans = std::max(ans, 
                        sum - (A[i + 1] - A[i]) - psum[len] - (psum[i + 2 + len] - psum[i + 2]) + static_cast<int64_t>(A[i]) * len * 2);
            }
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
