#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

constexpr int MAX = 5000;

void run_case() {
    int T, M;
    std::cin >> T >> M;

    std::vector<std::vector<int64_t>> comb(MAX + 1, std::vector<int64_t>(MAX + 1, 0));
    comb[0][0] = 1;
    for(int i = 1; i <= MAX; i++) {
        comb[i][0] = 1;
        comb[i][i] = 1;
        for(int j = 1; j < i; j++) {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
            comb[i][j] %= M;
        }
    }

    for(int _ = 0; _ < T; _++) {
        int N;
        std::cin >> N;
        
        std::vector<int> A(N);
        for(int i = 0; i < N; i++) {
            std::cin >> A[i];
        }

        int64_t ans = 1;
        int tot = std::accumulate(A.begin(), A.end(), 0);
        for(int i = 0; i < N; i++) {
            ans *= comb[tot][A[i]];
            ans %= M;
            tot -= A[i];
        }
        std::cout << ans << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
