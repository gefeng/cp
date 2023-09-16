#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = (int64_t)1e15;

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t lo = 1;
    int64_t hi = MAX; 
    int64_t ans = 0;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;

        int64_t lines = 1;
        int64_t len = 0;
        bool ok = true;
        for(int i = 0; i < N; i++) {
            if(A[i] > mid) {
                ok = false;
                break;
            }
            if(len + A[i] <= mid) {
                len += A[i] + 1;
            } else {
                lines += 1;
                len = A[i] + 1;
            } 
        }

        if(ok && lines <= M) {
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
    std::cin.tie(nullptr);

    run_case();
}
