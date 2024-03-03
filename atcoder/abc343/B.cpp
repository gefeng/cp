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

    std::vector<std::vector<int>> G(N, std::vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> G[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(G[i][j]) {
                std::cout << j + 1 << ' ';
            }
        }
        std::cout << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
