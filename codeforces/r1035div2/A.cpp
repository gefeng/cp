#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B, X, Y;
    std::cin >> A >> B >> X >> Y;

    if(A == B) {
        std::cout << 0 << '\n';
        return;
    }

    if(A > B) {
        std::cout << (A - 1 == B && A % 2 == 1 ? Y : -1) << '\n';
    } else {
        int cost = 0;
        if(X <= Y) {
            cost = (B - A) * X;
        } else {
            if((B - A) % 2 == 0) {
                cost = (B - A) / 2 * (X + Y); 
            } else {
                if(A % 2 == 1) {
                    cost = (B - A) / 2 * Y + (B - A + 1) / 2 * X;
                } else {
                    cost = (B - A) / 2 * X + (B - A + 1) / 2 * Y;
                }
            }
        }

        std::cout << cost << '\n';
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
