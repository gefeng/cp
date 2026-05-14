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
    int64_t K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> A(N);
    for(int i = 0; i < N; i++) {
        int M;
        std::cin >> M;
        for(int j = 0; j < M; j++) {
            int X;
            std::cin >> X;
            A[i].push_back(X);
        }
    }

    std::vector<int64_t> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    for(int i = 0; i < N; i++) {
        int len = A[i].size();
        int64_t c = std::min(K / len, B[i]);

        B[i] -= c;
        K -= len * c;
        if(B[i] || (B[i] == 0 && K == 0)) {
            std::cout << A[i][(K - 1 + len) % len] << '\n';
            return;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
