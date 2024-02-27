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
    std::vector<int> pos(N, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        pos[A[i] - 1] = i;
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;

        std::cout << (pos[L] < pos[R] ? L : R) + 1 << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
