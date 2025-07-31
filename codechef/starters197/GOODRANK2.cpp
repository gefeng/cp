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

    std::cout << 2 << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << i + 1 << " \n"[i == N - 1];
    }

    for(int i = N - 1; i >= 0; i--) {
        std::cout << i + 1 << " \n"[i == 0];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
