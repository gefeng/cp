#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X;
    std::cin >> N >> X;

    std::vector<int> A(N << 1);
    for(int i = 0; i < (N << 1); i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);

    for(int i = 0; i < N; i++) {
        if(A[i + N] - A[i] < X) {
            std::cout << "NO" << '\n';
            return;
        }
    }

    std::cout << "YES" << '\n';
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
