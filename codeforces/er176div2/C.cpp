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
    std::cin >> N >> M;

    std::vector<int> A(M);
    std::vector<int64_t> psum(M + 1, 0);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i];
        A[i] = std::min(A[i], N - 1);
    }

    int64_t ans = 0;
    std::sort(A.begin(), A.end());

    for(int i = 0; i < M; i++) {
        psum[i + 1] = psum[i] + A[i];
    }

    for(int l = 0, r = 0; r < M; r++) {
        while(l >= 0 && A[l] + A[r] >= N) {
            l -= 1;
        }
        if(l == r) {
            l = r + 1;
            continue;
        }
        int64_t cnt = int64_t(r - l - 1) * (A[r] - N + 1) + psum[r] - psum[l + 1];
        ans += cnt * 2;
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
