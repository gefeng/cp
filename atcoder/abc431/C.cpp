#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<int> A(N);
    std::vector<int> B(M);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::ranges::sort(A);
    std::ranges::sort(B);

    int ans = 0;
    for(int i = 0, j = 0; i < N && j < M; i++) {
        while(j < M && B[j] < A[i]) {
            j += 1;
        }
        if(j < M) {
            j += 1;
            ans += 1;
        }
    }

    std::cout << (ans >= K ? "Yes" : "No") << '\n'; 
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
