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

    if(N == 3) {
        std::cout << -1 << '\n';
        return;
    }

    if(N == 2) {
        std::cout << "2 1" << '\n';
        return;
    }

    std::cout << N - 1 << ' ' << N << ' ';
    for(int i = 1; i < N - 1; i++) {
        std::cout << i << " \n"[i == N - 2];
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
