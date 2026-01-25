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

    std::vector<int> a(N);
    for(int i = 0; i < M; i++) {
        int A, B;
        std::cin >> A >> B;
        A -= 1;
        B -= 1;
        a[A] += 1;
        a[B] += 1;
    }

    for(int i = 0; i < N; i++) {
        int64_t c = N - 1 - a[i]; 
        int64_t res = c >= 3 ? (c - 2) * (c - 1) * c / 6 : 0;
        std::cout << res << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
