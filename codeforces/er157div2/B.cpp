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

    std::vector<int> A(N * 2);
    for(int i = 0; i < N * 2; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    
    int dist = 0;
    for(int i = 1; i < N; i++) {
        dist += std::abs(A[i] - A[i - 1]) + std::abs(A[N + i] - A[N + i - 1]);
    }

    std::cout << dist << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << A[i] << ' ' << A[N + i] << '\n';
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
