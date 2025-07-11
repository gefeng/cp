#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> B(K);
    for(int i = 0; i < K; i++) {
        std::cin >> B[i];
    }

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end(), std::greater<int>());
    
    int l = 0;
    int r = N - 1;
    int64_t ans = 0;
    int p = K - 1;
    while(p >= 0 && B[p] == 1) {
        ans += A[r] * 2;
        r -= 1;
        p -= 1;
    }

    for(int i = 0; i <= p; i++) {
        int cnt = B[i];
        ans += A[l] + A[r];
        cnt -= 2;
        l += 1;
        r -= 1;
        while(cnt) {
            l += 1;
            cnt -= 1;
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
