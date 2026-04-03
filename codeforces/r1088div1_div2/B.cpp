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

    if(X == Y) {
        std::cout << 1 << '\n';
        for(int i = 0; i < X + Y; i++) {
            std::cout << (i < X ? 1 : -1) << " \n"[i == X + Y - 1];
        }
        return;
    }

    int d = std::abs(X - Y);
    int cnt = 0;
    for(int f = 1; f * f <= d; f++) {
        if(d % f == 0) {
            cnt++;
            if(d / f != f) {
                cnt++;
            }
        } 
    }

    std::cout << cnt << '\n';
    if(X >= Y) {
        for(int i = 0; i < std::min(X, Y); i++) {
            std::cout << "-1 1 ";
        }
        for(int i = 0; i < d; i++) {
            std::cout << 1 << " \n"[i == d - 1];
        }
    } else {
        for(int i = 0; i < std::min(X, Y); i++) {
            std::cout << "1 -1 ";
        }
        for(int i = 0; i < d; i++) {
            std::cout << -1 << " \n"[i == d - 1];
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
