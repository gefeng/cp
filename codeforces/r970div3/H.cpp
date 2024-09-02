#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::vector<int> B(Q);
    for(int i = 0; i < Q; i++) {
        std::cin >> B[i];
    }

    std::vector<int> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum[A[i]] += 1;
    }
    
    for(int i = 1; i <= N; i++) {
        psum[i] += psum[i - 1]; 
    }

    auto solve = [&](int x) {
        int lo = 0;
        int hi = x;
        int res = -1;

        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            int cnt = 0;
            int l = 0;
            int r = mid;
            while(l <= N) {
                cnt += psum[r] - (l == 0 ? 0 : psum[l - 1]);
                l += x;
                r += x;
                r = std::min(r, N);
            }

            if(cnt >= N / 2 + 1) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return res;
    };

    std::vector<int> ans(N + 1, -1);
    for(int i = 0; i < Q; i++) {
        if(ans[B[i]] == -1) {
            ans[B[i]] = solve(B[i]);
        }

        std::cout << ans[B[i]] << " \n"[i == Q - 1];
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
