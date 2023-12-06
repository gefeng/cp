#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<std::string> G(N);
    for(int i = 0; i < N; i++) {
        std::cin >> G[i];
    }

    std::vector<std::vector<int>> psum(N + 1, std::vector<int>(N + 1, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            psum[i + 1][j + 1] = psum[i + 1][j] + psum[i][j + 1] - psum[i][j] + (G[i][j] == 'B' ? 1 : 0);
        }
    }

    auto get_sum = [&](int r1, int c1, int r2, int c2) {
        int res = 0;
        if(r2 >= r1 && c2 >= c1) {
            res = psum[r2 + 1][c2 + 1] - psum[r2 + 1][c1] - psum[r1][c2 + 1] + psum[r1][c1];
        }
        return res;
    };

    auto solve = [&](int r, int c) {
        if(r < 0 || c < 0) {
            return (int64_t)0;
        }

        int x = (r % N + 1) % N;
        int y = (c % N + 1) % N;
        int64_t sum = 0;
        
        sum += (int64_t)get_sum(0, 0, N - 1, y - 1) * ((r + 1 - x) / N);
        sum += (int64_t)get_sum(0, 0, x - 1, N - 1) * ((c + 1 - y) / N);
        sum += (int64_t)get_sum(0, 0, x - 1, y - 1);
        sum += (int64_t)get_sum(0, 0, N - 1, N - 1) * ((r + 1 - x) / N) * ((c + 1 - y) / N);

        return sum;
    };

    for(int i = 0; i < Q; i++) {
        int A, B, C, D;
        std::cin >> A >> B >> C >> D;

        int64_t res = solve(C, D) - solve(A - 1, D) - solve(C, B - 1) + solve(A - 1, B - 1);

        std::cout << res << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
