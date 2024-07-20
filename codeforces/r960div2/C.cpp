#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        ans += A[i];
    }

    for(int t = 0; t < 2; t++) {
        std::vector<int> nxt(N, 0);
        std::vector<int> seen(N + 1, 0);
        int now = 0;
        for(int i = 0; i < N; i++) {
            if(seen[A[i]]) {
                now = std::max(now, A[i]);
            }
            seen[A[i]] = 1;
            nxt[i] = now;
            ans += now;
        }
        std::swap(A, nxt);
    }

    for(int i = 0; i < N; i++) {
        ans += int64_t(A[i]) * (N - i - 1);
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
