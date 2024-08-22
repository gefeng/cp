#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, S;
    std::cin >> N >> S;

    int x = N % 2 == 0 ? N / 2 - 1 : N / 2;
    int y = N - x;
    
    std::cout << S / y << '\n';
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
