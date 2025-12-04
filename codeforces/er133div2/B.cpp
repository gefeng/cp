#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> now(N, 0);

    std::iota(now.begin(), now.end(), 1);

    std::cout << N << '\n';
    for(int i = 0; i < N; i++) {
        if(i) {
            std::swap(now[i], now[i - 1]);
        }

        for(int j = 0; j < N; j++) {
            std::cout << now[j] << " \n"[j == N - 1];
        }
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
