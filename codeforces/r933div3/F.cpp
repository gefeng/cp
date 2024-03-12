#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<int> A(N);
    std::vector<int> B(M);
    std::vector<int> C(K);
    int max_gap = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        if(i) {
            max_gap = std::max(max_gap, A[i] - A[i - 1]);
        }
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    for(int i = 0; i < K; i++) {
        std::cin >> C[i];
    }

    std::sort(B.begin(), B.end());
    std::sort(C.begin(), C.end());

    int64_t lo = 0;
    int64_t hi = max_gap;
    int64_t ans = -1;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;

        bool ok = true;
        int cnt = 0;
        int p = -1;
        for(int i = 1; i < N; i++) {
            if(A[i] - A[i - 1] > mid) {
                p = i;
                cnt += 1;
            }
        }

        if(cnt == 1) {
            int64_t l = (int64_t)A[p] - mid;
            int64_t r = (int64_t)mid + A[p - 1];
            ok = false;
            if(l > r) {
                ok = false;
            } else {
                for(int i = 0; i < M; i++) {
                    auto it = std::lower_bound(C.begin(), C.end(), l - B[i]);
                    if(it != C.end() && *it <= r - B[i]) {
                        ok = true; 
                        break;
                    }
                }
            }
        } else if(cnt > 1) {
            ok = false;
        }

        if(ok) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
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
