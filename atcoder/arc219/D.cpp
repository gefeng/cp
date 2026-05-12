#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<std::vector<int>> A(N, std::vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> A[i][j];
        }
    }

    int xor_sum = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if((i + j) % 2 == 1) {
                xor_sum ^= A[i][j] % (K + 1);
            }
        }
    }

    std::cout << (xor_sum == 0 ? "Bob" : "Alice") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
