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
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(N % 2 == 0) {
        std::cout << 2 << '\n' << 1 << ' ' << N << '\n' << 1 << ' ' << N << '\n';
    } else {
        std::cout << 4 << '\n' << 1 << ' ' << N << '\n' << 1 << ' ' << N - 1 << '\n' << N - 1 << ' ' << N << '\n' << N - 1 << ' ' << N << '\n';
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
