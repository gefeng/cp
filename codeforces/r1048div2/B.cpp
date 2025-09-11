#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);

    int64_t ans = 0;
    int64_t t = 0;
    if(M > N) {
        ans += static_cast<int64_t>(M - N + 1) * A[0];
        t += M - N + 1;
        M = N - 1;
    }

    for(int i = N - M; i < N; i++) {
        t += 1;
        ans += t * A[i];
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
