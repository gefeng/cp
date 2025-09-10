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
    int N;
    std::cin >> N;

    int m = N * (N - 1) / 2;
    std::vector<int> A(m);
    for(int i = 0; i < m; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);

    if(N == 2) {
        std::cout << A[0] << '\n';
        return;
    }

    int64_t ans = A[0] + A[1];
    int now = 2;
    int p = 1;
    while(p + now < m) {
        p += now;
        ans += A[p];
        now += 1;
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
