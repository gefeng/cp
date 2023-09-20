#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B;
    std::cin >> A >> B;

    int ans = 0;
    int dist = 0;
    for(int i = 29; i >= 0; i--) {
        int b1 = (A & (1 << i)) ? 1 : 0;
        int b2 = (B & (1 << i)) ? 1 : 0;

        if(b1 == b2) {
            ans |= b1 << i;
        } else {
            int d = (b1 << i) - (b2 << i);
            if(abs(dist - d) < abs(dist + d)) {
                ans |= 1 << i;
                dist -= d;
            } else {
                dist += d;
            }
        }
    }

    std::cout << ans << '\n';
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
