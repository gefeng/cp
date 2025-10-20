#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int>(2e9);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int max_v = 0;
    for(int i = 0; i < N; i++) {
        max_v = std::max(max_v, A[i]);
        if(i % 2 == 1) {
            A[i] = max_v;
        }
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        if(i % 2 == 0) {
            int l = i == 0 ? INF : A[i - 1];
            int r = i == N - 1 ? INF : A[i + 1];
            if(A[i] < l && A[i] < r) {
                continue;
            }
            ans += A[i] - (std::min(l, r) - 1);
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
