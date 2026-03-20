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

    std::vector<std::vector<int>> A(N, std::vector<int>(N, 0));
    std::vector<int> freq(N * N + 1, 0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> A[i][j];
            freq[A[i][j]] += 1;
        }
    }

    int max_v = *std::ranges::max_element(freq);

    std::cout << (max_v <= N * N - N ? "Yes" : "No") << '\n';
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
