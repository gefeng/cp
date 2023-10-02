#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i];
    }

    for(int i = 1; i <= N; i++) {
        auto it = std::lower_bound(A.begin(), A.end(), i);
        std::cout << *it - i << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
