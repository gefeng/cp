#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::string S;
    std::cin >> S;
    
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < N; ) {
        if(S[i] == '1') {
            i += 1;
            cnt = 0;
        } else {
            if(++cnt == M) {
                for(int j = 0; j < K && i + j < N; j++) {
                    S[i + j] = '1';
                }
                i += K;
                cnt = 0;
                ans += 1;
            } else {
                i += 1;
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
