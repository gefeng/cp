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
    
    if(K == 1) {
        std::cout << N << '\n';
        return;
    }

    K -= 1;
    
    int hb = -1;
    for(int i = 30; i >= 0; i--) {
        if(N & (1 << i)) {
            hb = i;
            break;
        }
    }

    for(int i = 0; i <= hb; i++) {
        if(N & (1 << i)) {
            continue;
        }
        int cnt = 1;
        for(int j = i - 1; j >= 0; j--) {
            if(N & (1 << j)) {
                continue;
            }
            cnt *= 2;
        }
        if(K > cnt) {
            K -= cnt;
        } else {
            int ans = 1 << i;
            for(int j = i - 1; j >= 0; j--) {
                if(N & (1 << j)) {
                    ans |= 1 << j;
                    continue;
                }
                if(cnt / 2 < K) {
                    ans |= 1 << j;
                    K -= cnt / 2;
                }
                cnt /= 2;
            }

            for(int j = hb; j > i; j--) {
                if(N & (1 << j)) {
                    ans |= 1 << j;
                } 
            }
            std::cout << ans << '\n';
            return;
        }
    }

    std::cout << -1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
