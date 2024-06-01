#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    int64_t ans = N;
    for(int i = 0; i < 61; i++) {
        int64_t missing = (int64_t)1 << i;
        if(N & missing) {
            continue;
        }

        int64_t d = 0;
        if(missing >= N) {
            d = missing - N; 
        } else {
            int64_t x = N | missing;
            int64_t y = N | missing;
            for(int j = i - 1; j >= 0; j--) {
                if(x & ((int64_t)1 << j)) {
                    x ^= (int64_t)1 << j;
                }
            }

            for(int j = i + 1; j < 61; j++) {
                if(y & ((int64_t)1 << j)) {
                    y ^= (int64_t)1 << j;
                    for(int k = 0; k < j; k++) {
                        y |= (int64_t)1 << k;
                    }
                    break;
                }
            } 

            d = std::min(x - N, N - y);
        }
        
        if(d <= M) {
            ans |= missing;
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
