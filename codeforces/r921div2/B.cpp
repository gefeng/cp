#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    /*a + b + c + d = x
    c1x + c2x + c3x + c4x = s
    (c1 + c2 + c3 + c4)x = s
    c1 + c2 + c3 + c4 >= n*/

    int X, N;
    std::cin >> X >> N;

    int ans = 1;
    for(int f = 1; f * f <= X; f++) {
        if(X % f == 0) {
            int a = X / f;
            if(a >= N) {
                ans = std::max(ans, f);
            }

            if(f >= N) {
                ans = std::max(ans, X / f);
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
