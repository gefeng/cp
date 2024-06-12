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
    int64_t K;
    std::cin >> X >> Y >> Z >> K;

    int64_t ans = 0;
    for(int64_t a = 1; a <= X; a++) {
        for(int64_t b = 1; b <= Y; b++) {
            if(K % (a * b) == 0) {
                int64_t c = K / (a * b);
                if(c <= Z) {
                    ans = std::max(ans, (X - a + 1) * (Y - b + 1) * (Z - c + 1));
                }
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
