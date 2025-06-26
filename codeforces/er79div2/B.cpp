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
    int64_t S;
    std::cin >> N >> S;

    std::vector<int> A(N);
    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        psum[i + 1] = psum[i] + A[i];
    }

    int64_t sum = std::accumulate(A.begin(), A.end(), int64_t(0));
    int min_v = *std::min_element(A.begin(), A.end());
    
    if(sum <= S || min_v > S) {
        std::cout << 0 << '\n';
        return;
    }

    int max_v = 0;
    int ans = -1;
    for(int i = 0; i < N; i++) {
        int lo = 0;
        int hi = N - 1;
        int res = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            sum = psum[mid + 1] - (mid >= i ? A[i] : 0);
            if(sum <= S) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        int cnt = res + 1 - (res >= i ? 1 : 0);
        if(cnt > max_v) {
            max_v = cnt;
            ans = i;
        }
    } 

    std::cout << ans + 1 << '\n';
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
