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
    int max_v = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        max_v = std::max(max_v, A[i]);
    }

    int cnt = 0;
    for(int x : A) {
        if(max_v == x) {
            cnt += 1;
        }
    }

    if(A[0] != max_v) {
        std::cout << max_v - A[0] + 1 << '\n';
    } else {
        std::cout << (cnt == 1 ? 0 : 1) << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
