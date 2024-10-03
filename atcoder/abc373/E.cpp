#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    int64_t K;
    std::cin >> N >> M >> K;

    std::vector<std::pair<int64_t, int>> A(N);
    std::vector<int64_t> psum(N + 1, 0);
    int64_t tot = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
        A[i].second = i;
        tot += A[i].first;
    }

    std::sort(A.begin(), A.end());
    
    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] + A[i].first;
    }

    auto check = [&](int who, int64_t t) {
        int64_t have = A[who].first + t;
        int64_t free = K - tot - t;

        auto it = std::upper_bound(A.begin(), A.end(), have, [](int64_t x, std::pair<int64_t, int>& a) {
                    return x < a.first; 
                });

        int lo = 0;
        int hi = N - 1;
        int res = 0;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
         
            int j = std::max(mid, int(it - A.begin()));

            int64_t sum = psum[j] - psum[mid];
            int64_t cnt = j - mid;
            if(who >= mid) {
                sum -= A[who].first;
                cnt -= 1;
            }
            
            int64_t need = std::max(int64_t(0), (have + 1) * cnt - sum);
            if(need <= free) {
                res = cnt + N - j;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return res < M;
    };

    std::vector<int64_t> ans(N, -1);
    for(int i = 0; i < N; i++) {
        int64_t lo = 0;
        int64_t hi = K - tot;
        while(lo <= hi) {
            int64_t mid = (lo + hi) >> 1;
            
            if(check(i, mid)) {
                ans[A[i].second] = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
