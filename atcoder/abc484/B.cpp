#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int K;
    std::cin >> K;

    std::vector<int> A(K);
    for(int i = 0; i < K; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);
    
    if(A.back() != 9) {
        std::cout << -1 << '\n';
    } else {
        std::cout << A[0] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
