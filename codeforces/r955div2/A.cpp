#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X1, Y1, X2, Y2;
    std::cin >> X1 >> Y1 >> X2 >> Y2;

    if(X1 == Y1) {
        std::cout << (X2 != Y2 ? "Yes" : "No") << '\n';
        return;
    }

    if(X1 < Y1) {
        std::cout << (X2 > Y2 ? "No" : "Yes") << '\n';
    } else {
        std::cout << (X2 > Y2 ? "Yes" : "No") << '\n';
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
