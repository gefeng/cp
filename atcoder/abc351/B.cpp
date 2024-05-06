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

    std::vector<std::string> A(N);
    std::vector<std::string> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(A[i][j] != B[i][j]) {
                std::cout << i + 1 << ' ' << j + 1 << '\n';
                return;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
