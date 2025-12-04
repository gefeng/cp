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
    
    if(X == Y) {
        std::cout << X << ' ';
        for(int i = 0; i < X; i++) {
            std::cout << 0 << " \n"[i == X - 1];
        }
        std::cout << Z << ' ';
        for(int i = 0; i < Z; i++) {
            std::cout << 0 << " \n"[i == Z - 1];
        }
        std::cout << Z << ' ';
        for(int i = 0; i < Z; i++) {
            std::cout << 0 << " \n"[i == Z - 1];
        }
    } else {
        std::cout << Y << ' ';
        for(int i = 0; i < Y; i++) {
            std::cout << 0 << " \n"[i == Y - 1];
        }

        std::cout << X + Z << ' ';
        for(int i = 0; i < X + Z; i++) {
            std::cout << (i < X ? 0 : 1) << " \n"[i == X + Z - 1];
        }

        std::cout << Y + Z << ' ';
        for(int i = 0; i < Y + Z; i++) {
            std::cout << (i < Z ? 1 : 0) << " \n"[i == Y + Z - 1];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
