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

    std::vector<int> prefix(N + 1, 0);
    std::vector<int> suffix(N + 1, 0);
    prefix[1] = 1;
    suffix[1] = 1;
    for(int i = 2; i <= N; i++) {
        prefix[i] = prefix[i - 1] + (A[i - 1] < A[i - 2] ? 0 : 1);
        suffix[i] = suffix[i - 1] + (A[N - i] < A[N - i + 1] ? 0 : 1);
    }

    int ans = N;
    for(int i = 0; i <= N; i++) {
        ans = std::min(ans, prefix[i] + std::max(0, suffix[N - i] - 1));
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
