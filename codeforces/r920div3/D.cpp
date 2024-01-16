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
    
    std::vector<int> A(N);
    std::vector<int> B(M);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end(), std::greater<int>());

    int l1 = 0;
    int l2 = 0;
    int r1 = N - 1;
    int r2 = M - 1;
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        int d1 = std::abs(A[l1] - B[l2]);
        int d2 = std::abs(A[r1] - B[r2]);
        if(d1 > d2) {
            ans += d1;
            l1 += 1;
            l2 += 1;
        } else {
            ans += d2;
            r1 -= 1;
            r2 -= 1;
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
