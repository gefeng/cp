#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    int bal = 0;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int X;
        std::cin >> X;
        if(X == 0) {
            if(bal) {
                ans += 1;
            }
            bal = std::max(0, bal - 1);
        } else {
            if(X >= K) {
                bal += X;
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
