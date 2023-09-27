#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    int64_t X;
    std::cin >> N >> K >> X;

    if((int64_t)(1 + K) * K / 2 <= X && (int64_t)(N - K + 1 + N) * K / 2 >= X) {
        std::cout << "YES" << '\n'; 
    } else {
        std::cout << "NO" << '\n';
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
