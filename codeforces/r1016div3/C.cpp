#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X, K;
    std::cin >> X >> K;
    
    if(X % 2 == 0) {
        std::cout << (X == 2 && K == 1 ? "Yes" : "No") << '\n';
        return;
    }
    
    if(K == 1 || X == 1) {
        if(X == 1) {
            for(int i = 0; i < K - 1; i++) {
                X = X * 10 + 1;
            }
        }
        if(X == 1) {
            std::cout << "No" << '\n';
            return;
        }
        for(int f = 2; f * f <= X; f++) {
            if(X % f == 0) {
                std::cout << "No" << '\n';
                return;
            }
        }

        std::cout << "Yes" << '\n';
    } else {
        std::cout << "No" << '\n';
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
