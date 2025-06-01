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

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    if(N % 2 == 1) {
        std::cout << "NO" << '\n';
        return;
    }
    
    int64_t m_x = A[0].first + A[N / 2].first;
    int64_t m_y = A[0].second + A[N / 2].second;
    
    for(int i = 1; i < N / 2; i++) {
        if(A[i].first + A[N / 2 + i].first != m_x || A[i].second + A[N / 2 + i].second != m_y) {
            std::cout << "NO" << '\n';
            return;
        }
    }

    std::cout << "YES" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
