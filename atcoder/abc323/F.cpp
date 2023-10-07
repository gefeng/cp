#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t X1, Y1, X2, Y2, X3, Y3;
    std::cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;

    auto dist = [](int64_t x1, int64_t y1, int64_t x2, int64_t y2) {
        return std::abs(x1 - x2) + std::abs(y1 - y2);
    };
    
    int64_t ans = 0;
    int64_t d = dist(X2, Y2, X3, Y3);
    if(X2 == X3) {
        if(Y2 > Y3) {
            ans = X1 == X2 && Y1 < Y2 ? dist(X1, Y1, X2, Y2 + 1) + d + 2 : dist(X1, Y1, X2, Y2 + 1) + d;
        } else {
            ans = X1 == X2 && Y1 > Y2 ? dist(X1, Y1, X2, Y2 - 1) + d + 2 : dist(X1, Y1, X2, Y2 - 1) + d;
        }
    } else if(Y2 == Y3) {
        if(X2 > X3) {
            ans = Y1 == Y2 && X1 < X2 ? dist(X1, Y1, X2 + 1, Y2) + d + 2 : dist(X1, Y1, X2 + 1, Y2) + d;
        } else {
            ans = Y1 == Y2 && X1 > X2 ? dist(X1, Y1, X2 - 1, Y2) + d + 2 : dist(X1, Y1, X2 - 1, Y2) + d;
        }
    } else {
        if(X2 > X3 && Y2 < Y3) {        // top left
            ans = std::min(dist(X1, Y1, X2, Y2 - 1), dist(X1, Y1, X2 + 1, Y2)) + d + 2;
        } else if(X2 < X3 && Y2 < Y3) { // top right
            ans = std::min(dist(X1, Y1, X2 - 1, Y2), dist(X1, Y1, X2, Y2 - 1)) + d + 2; 
        } else if(X2 < X3 && Y2 > Y3) { // bot right
            ans = std::min(dist(X1, Y1, X2 - 1, Y2), dist(X1, Y1, X2, Y2 + 1)) + d + 2; 
        } else {                        // bot left
            ans = std::min(dist(X1, Y1, X2, Y2 + 1), dist(X1, Y1, X2 + 1, Y2)) + d + 2; 
        } 
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
