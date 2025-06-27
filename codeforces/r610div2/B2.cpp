#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, P, K;
    std::cin >> N >> P >> K;
    
    std::vector<int> A(N);
    std::vector<int> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] + A[i];
    }

    auto solve = [&](int st) {
        int have = P;
        int cnt = 0;
        for(int i = st; i < N; ) {
            if(i + K - 1 < N && A[i + K - 1] <= have) {
                cnt += K;
                have -= A[i + K - 1];
                i += K;
            } else {
                break;
            }
        } 

        int lo = 0;
        int hi = st - 1;
        int p = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            if(psum[mid + 1] <= have) {
                p = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if(p != -1) {
            cnt += p + 1;
        }
        return cnt;
    };

    int ans = 0;
    for(int i = 0; i < K; i++) {
        ans = std::max(ans, solve(i));
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
