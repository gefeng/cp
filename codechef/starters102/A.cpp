#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)1e9 + 7;

void run_case() {
    int N;
    std::cin >> N;
    
    std::string S;
    std::cin >> S;

    int64_t ans = 1;
    for(int i = 2; i < N; i += 2) {
        int b1 = S[i - 2] - '0';
        int b2 = S[i - 1] - '0';
        int b3 = S[i] - '0'; 

        if(b1 != b2) {
            if(b3 == 1) {
                ans *= 2;
                ans %= MOD;
            }     
        } else {
            if(b1 == 0) {
                if(b3 == 0) {
                    ans *= 3;
                    ans %= MOD;
                } else {
                    std::cout << 0 << '\n';
                    return;
                }
            } else {
                if(b3 == 1) {
                    ans *= 2;
                    ans %= MOD;
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
