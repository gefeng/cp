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
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i];
    }

    int64_t sum = std::accumulate(A.begin(), A.end(), int64_t(0));

    std::vector<int> ans(M);
    int l = 0;
    int r = -1;
    for(int i = 0; i < M; i++) {
        if(sum < N - r - 1) {
            std::cout << -1 << '\n';
            return;
        }
        
        int lo = l;
        int hi = std::min(N - 1, r + 1);
        int p = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            if(std::max(r, mid + A[i] - 1) + 1 + sum - A[i] >= N) {
                p = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        if(p == -1) {
            std::cout << -1 << '\n';
            return;
        }

        ans[i] = p;
        l = p + 1;
        r = std::max(r, p + A[i] - 1); 
        if(r > N - 1) {
            std::cout << -1 << '\n';
            return;
        }
        sum -= A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cout << ans[i] + 1 << " \n"[i == M - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
