#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int K, G, M;
    std::cin >> K >> G >> M;

    int x = 0;
    int y = 0;
    while(K--) {
        if(x == G) {
            x = 0;
        } else if(y == 0) {
            y = M;
        } else {
            int d = std::min(G - x, y);
            y -= d;
            x += d;
        }
    }

    std::cout << x << ' ' << y << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
