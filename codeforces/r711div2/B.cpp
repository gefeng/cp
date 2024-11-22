#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, W;
    std::cin >> N >> W;

    std::array<int, 30> freq = {};
    for(int i = 0; i < N; i++) {
        int X;
        std::cin >> X;
        
        int p = 0;
        while(X != 1) {
            X /= 2;
            p += 1;
        }
        
        freq[p] += 1;
    }

    int ans = 0;
    while(true) {
        bool end = true;
        int w = W;
        for(int i = 29; i >= 0; i--) {
            while(freq[i]) {
                end = false;

                int x = int(std::pow(2, i));
                if(x <= w) {
                    w -= x;
                    freq[i] -= 1;
                } else {
                    break;
                }
            }
        }

        if(end) {
            break;
        }

        ans += 1;
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
