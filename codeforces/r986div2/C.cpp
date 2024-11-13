#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, V;
    std::cin >> N >> M >> V;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] + A[i];
    }

    std::vector<int> suffix(N + 1, 0);
    int64_t sum = 0;
    for(int i = N - 1; i >= 0; i--) {
        sum += A[i];
        if(sum >= V) {
            suffix[N - i] = suffix[N - i - 1] + 1;
            sum = 0;
        } else {
            suffix[N - i] = suffix[N - i - 1];
        }
    }

    sum = 0;
    int prefix = 0;
    int64_t ans = suffix[N] >= M ? 0 : -1;
    for(int i = 0; i < N; i++) {
        int lo = i;
        int hi = N - 1;
        int res = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            int cnt = prefix + suffix[N - 1 - mid];
            if(cnt >= M) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        if(res != -1) {
            ans = std::max(ans, psum[res + 1] - psum[i]);
        }

        sum += A[i];
        if(sum >= V) {
            sum = 0;
            prefix += 1;
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
