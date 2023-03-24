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

    std::vector<int> A(N - 1);
    for(int i = 0; i < N - 1; i++) {
        std::cin >> A[i];
    }

    std::vector<int> cnt(N, 0);
    for(int i = 0; i < N - 1; i++) {
        cnt[A[i] - 1] += 1;
    }

    for(int i = 0; i < N; i++) {
        std::cout << cnt[i] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
