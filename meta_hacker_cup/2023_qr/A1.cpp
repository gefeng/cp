#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case(int T) {
    int S, D, K;
    std::cin >> S >> D >> K;

    int a = (S + D) * 2;
    int b = S + D * 2;
    int c = S + D * 2;

    
    bool ans = a >= K + 1 && b >= K && c >= K;
    
    std::cout << "Case #" << T << ": " << (ans ? "YES" : "NO") << '\n';
}

int main() {
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
