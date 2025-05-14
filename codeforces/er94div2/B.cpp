#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int P, F, X, Y, S, W;
    std::cin >> P >> F >> X >> Y >> S >> W;
    
    if(S > W) {
        std::swap(S, W);
        std::swap(X, Y);
    } 
 
    int ans = 0;
    for(int i = 0; i <= X; i++) {
        if(int64_t(i) * S > P) {
            break;
        }
        
        int j = std::min(Y, (P - i * S) / W);

        int left_s = X - i;
        int left_w = Y - j;

        int x = std::min(left_s, F / S);
        int y = std::min(left_w, (F - x * S) / W);

        ans = std::max(ans, i + j + x + y);
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
