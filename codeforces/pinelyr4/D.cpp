#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = int(2e5);

std::vector<int> is_prime;

void run_case() {
    int N;
    std::cin >> N;

    std::array<int, 6> a = {1, 2, 2, 3, 3, 4};
    if(N <= 6) {
        std::cout << a[N - 1] << " \n";
        for(int i = 0; i < N; i++) {
            std::cout << a[i] << " \n"[i == N - 1]; 
        }
    } else {
        std::cout << 4 << " \n";
        for(int i = 0; i < N; i++) {
            std::cout << (i % 4) + 1 << " \n"[i == N - 1];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
