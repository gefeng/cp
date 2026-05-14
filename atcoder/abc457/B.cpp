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

    std::vector<std::vector<int>> A(N);
    for(int i = 0; i < N; i++) {
        int M;
        std::cin >> M;
        for(int j = 0; j < M; j++) {
            int X;
            std::cin >> X;
            A[i].push_back(X);
        }
    }

    int X, Y;
    std::cin >> X >> Y;
    X--;
    Y--;

    std::cout << A[X][Y] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
