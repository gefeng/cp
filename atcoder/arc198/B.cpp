#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X, Y, Z;
    std::cin >> X >> Y >> Z;

    if(X * 2 < Y) {
        std::cout << "No" << '\n';
        return;
    }

    int a = std::min(Y / 2, X);  // 101

    if(Y % 2 == 0) {
        if(Z <= a) {
            std::cout << "Yes" << '\n';
            return;
        }
        std::cout << (X >= Z ? "Yes" : "No") << '\n';
    } else {
        if(Z == 0) {
            std::cout << "No" << '\n';
            return;
        }
        
        if(Z > a) {
            std::cout << (X >= Z ? "Yes" : "No") << '\n';
            return;
        }

        X -= a;
        std::cout << (X == 0 ? "No" : "Yes") << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
