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

    std::vector<std::array<int, 3>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i][0] >> A[i][1];
        A[i][2] = i;
    }

    auto cmp = [](const auto& a, const auto& b) {
        int64_t x = (int64_t)a[0] * (b[0] + b[1]);
        int64_t y = (int64_t)b[0] * (a[0] + a[1]);
        if(x == y) {
            return a[2] < b[2];
        }
        return x > y;
    };

    std::sort(A.begin(), A.end(), cmp);

    for(int i = 0; i < N; i++) {
        std::cout << A[i][2] + 1 << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
