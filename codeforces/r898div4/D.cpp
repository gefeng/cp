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

    std::string S;
    std::cin >> S;

    int ans = 0;
    for(int i = 0; i <= N - K; i++) {
        if(S[i] == 'B') {
            for(int j = 0; j < K; j++) {
                S[j + i] = 'W';
            }
            i += K - 1;
            ans += 1;
        }
    }

    for(int i = N - K; i < N; i++) {
        if(S[i] == 'B') {
            ans += 1;
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
