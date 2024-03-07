#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)1e18;

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(M);
    std::vector<int64_t> diff(N + 1, 0);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    auto get_dist = [&](int from, int to) {
        if(from < to) {
            return to - from;
        }
        return N - (from - to);
    };

    auto update = [&](int from, int to, int d) {
        if(from <= to) {
            diff[from] += d;
            diff[to] -= d;
        } else {
            diff[from] += d;
            diff[N] -= d;
            diff[0] += d;
            diff[to] -= d;
        }
    };

    for(int i = 0; i < M - 1; i++) {
        update(A[i], A[i + 1], get_dist(A[i + 1], A[i]));    
        update(A[i + 1], A[i], get_dist(A[i], A[i + 1]));
    }

    int64_t sum = 0;
    int64_t ans = INF; 
    for(int i = 0; i < N; i++) {
        sum += diff[i];
        ans = std::min(ans, sum);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
