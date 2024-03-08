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
    }

    std::vector<int> dp1(N, 0);
    std::vector<int> dp2(N, 0);
    dp1[0] = 1;
    dp2[N - 1] = 1;
    for(int i = 1; i < N; i++) {
        dp1[i] = i + 1;
        dp1[i] = std::min(dp1[i], dp1[i - 1] + 1);
        dp1[i] = std::min(dp1[i], A[i]);
    }

    for(int i = N - 2; i >= 0; i--) {
        dp2[i] = N - i;
        dp2[i] = std::min(dp2[i], dp2[i + 1] + 1);
        dp2[i] = std::min(dp2[i], A[i]);
    } 

    std::vector<int> size(N, 0);
    size[0] = 1;
    size[N - 1] = 1;

    for(int i = 1; i < N - 1; i++) {
        size[i] = std::min(dp1[i], size[i - 1] + 1);
    }

    int ans = 1;
    for(int i = N - 2; i > 0; i--) {
        size[i] = std::min(size[i], std::min(dp2[i], size[i + 1] + 1));
        ans = std::max(ans, size[i]);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
