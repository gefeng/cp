#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X;
    std::cin >> N >> X;

    int64_t K;
    std::cin >> K;

    std::string S;
    std::cin >> S;
    
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'L') {
            X -= 1;
        } else {
            X += 1;
        }
        K -= 1;
        if(X == 0) {
            ans += 1;
            break;
        }
    }

    if(X) {
        std::cout << ans << '\n';
        return;
    }

    for(int i = 0; i < N; i++) {
        if(K) {
            if(S[i] == 'L') {
                X -= 1;
            } else {
                X += 1;
            }
            K -= 1;
            if(X == 0) {
                ans += 1;
                ans += K / (i + 1);
                break;
            }
        } else {
            break;
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
