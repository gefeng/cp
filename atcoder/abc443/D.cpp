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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    std::vector<int> a(A);

    int64_t ans = 0;
    for(int i = 1; i < N; i++) {
        a[i] = std::min(a[i], a[i - 1] + 1);
    }

    for(int i = N - 2; i >= 0; i--) {
        a[i] = std::min(a[i], a[i + 1] + 1);
    }

    for(int i = 0; i < N; i++) {
        ans += A[i] - a[i];
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
