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

    int cnt = Y / 2;
    X = std::max(0, X - cnt * 7); 

    if(Y % 2 == 1) {
        cnt += 1;
        X = std::max(0, X - 11);
    }

    if(X) {
        cnt += (X + 14) / 15;
    }

    std::cout << cnt << '\n';
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
