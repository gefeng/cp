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

    int t = 1;
    while(true) {
        int64_t d = (int64_t)Y * t - (int64_t)10 * (X - Y);
        if(d <= (int64_t)100 * t) {
            break;
        } 

        t += 1;
    }

    std::cout << t << '\n';
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
