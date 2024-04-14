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

    int64_t sum = 0;
    for(int i = 1, j = 1; i <= N; i += 1, j += 2) {
        sum += i * j;
    }

    std::cout << sum << ' ' << N * 2 << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << 1 << ' ' << i + 1 << ' ';
        for(int j = 1; j <= N; j++) {
            std::cout << j << " \n"[j == N];
        }

        std::cout << 2 << ' ' << N - i << ' ';
        for(int j = N; j >= 1; j--) {
            std::cout << j << " \n"[j == 1];
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
