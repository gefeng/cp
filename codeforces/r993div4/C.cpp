#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int M, A, B, C;
    std::cin >> M >> A >> B >> C;
    
    int row_1 = M;
    int row_2 = M;
    
    row_1 = std::max(0, row_1 - A);
    row_2 = std::max(0, row_2 - B);
    
    int d = std::min(row_1, C);
    C -= d;
    row_1 -= d;
    
    d = std::min(row_2, C);
    C -= d;
    row_2 -= d;
    
    std::cout << (M << 1) - row_1 - row_2 << '\n';
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
