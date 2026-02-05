#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, T;
    std::cin >> N >> T;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int t = 0;
    int ans = 0;
    int i = 0;
    while(i < N) {
        ans += A[i] - t;
        t = A[i++] + 100;
        i = std::upper_bound(A.begin() + i, A.end(), t) - A.begin();
    }

    ans += std::max(0, T - t);

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
