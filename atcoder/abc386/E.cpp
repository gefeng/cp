#include <iostream>
#include <utility> 
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(int N, int lv_t, int64_t sum, bool rev, std::vector<int64_t>& A, int lv, int p, int64_t now, int64_t& ans) {
    if(lv_t == lv) {
        ans = std::max(ans, rev ? (sum ^ now) : now);
        return;
    }

    for(int i = p; i < N; i++) {
        dfs(N, lv_t, sum, rev, A, lv + 1, i + 1, now ^ A[i], ans);
    }
}

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t sum = 0;
    for(int64_t x : A) {
        sum ^= x;
    }

    int64_t ans = 0;
    int lv_t = std::min(K, N - K);
    dfs(N, lv_t, sum, lv_t == N - K, A, 0, 0, 0, ans);
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
