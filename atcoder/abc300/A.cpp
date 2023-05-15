#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, A, B;
    std::cin >> N >> A >> B;

    std::vector<int> C(N);
    for(int i = 0; i < N; i++) {
        std::cin >> C[i];
    }

    for(int i = 0; i < N; i++) {
        if(A + B == C[i]) {
            std::cout << i + 1 << '\n';
            return;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
