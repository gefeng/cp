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

    std::vector<int> seen(N + 1, 0);
    std::vector<int> suffix(N + 1, 0);
    for(int i = N - 1; i >= 0; i--) {
        if(!seen[A[i]]) {
            seen[A[i]] = 1;
            suffix[N - i] = suffix[N - i - 1] + 1;
        } else {
            suffix[N - i] = suffix[N - i - 1];
        }
    }

    seen.assign(N + 1, 0);
    int ans = 0;
    int prefix = 0;
    for(int i = 0; i < N; i++) {
        if(!seen[A[i]]) {
            seen[A[i]] = 1;
            prefix += 1;
        }
        ans = std::max(ans, prefix + suffix[N - i - 1]);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
