#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t A, B, C, D;
    std::cin >> A >> B >> C >> D;

    int64_t ans = 0;
    int64_t dx = C - A;
    int64_t dy = D - B;
    
    A %= 4;
    B %= 2;
    A = (A + 4) % 4;
    B = (B + 2) % 2;
    C = A + dx;
    D = B + dy;

    auto f = [](int64_t x, int64_t y) {
        int rx = x % 4;
        int ry = y % 2;
        
        int64_t area = ((x - rx) / 4) * ((y - ry) / 2) * 8;
        
        if(rx) {
            int64_t extra = 0;
            if(rx == 1) {
                extra = 3;
            } else if(rx == 2) {
                extra = 6;
            } else {
                extra = 7;
            }

            area += (y - ry) / 2 * extra;

            if(ry) {
                if(rx == 1) {
                    extra = 2;
                } else if(rx == 2 || rx == 3) {
                    extra = 3;
                }
                area += extra;
            }
        }

        if(ry) {
            area += (x - rx) / 4 * 4;
        }

        return area;
    };

    ans = f(C, D) - f(A, D) - f(C, B) + f(A, B);
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
