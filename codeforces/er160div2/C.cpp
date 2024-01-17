#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int M;
    std::cin >> M;
    
    std::array<int, 30> b = {};
    for(int i = 0; i < M; i++) {
        int T, V;
        std::cin >> T >> V;
        if(T == 1) {
            b[V] += 1;
        } else {
            int x = V;
            int have = 0;
            
            bool ok = true;
            for(int j = 0; j < 30; j++) {
                have /= 2;
                have += b[j];
                if(x & (1 << j)) {
                    have -= 1; 
                    if(have < 0) {
                        ok = false;
                        break;
                    }
                }
            }
            std::cout << (ok ? "Yes" : "No") << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
