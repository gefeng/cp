#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X, Y;
    std::cin >> X >> Y;

    if(X < 2) {
        std::cout << "No" << '\n';
        return;
    }
    
    if(Y == 0) {
        if(X % 3 == 0) {
            std::cout << "Yes" << '\n';
        } else {
            std::cout << "No" << '\n';
        }
    } else if(Y > 0) {
        int t = Y;
        if(t * 2 == X) {
            std::cout << "Yes" << '\n';
        } else if(t * 2 < X) {
            std::cout << ((X - t * 2) % 3 == 0 ? "Yes" : "No") << '\n';
        } else {
            std::cout << "No" << '\n';
        }
    } else {
        int t = -Y;
        if(t * 4 == X) {
            std::cout << "Yes" << '\n';
        } else if(t * 4 < X) {
            std::cout << ((X - t * 4) % 3 == 0 ? "Yes" : "No") << '\n';
        } else {
            std::cout << "No" << '\n';
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
