#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    //0011
    //001
    //0001

    int N, K;
    std::cin >> N >> K;

    std::string S;
    std::cin >> S;

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        cnt += S[i] - '0';
    }

    if(cnt > K) {
        for(int i = 0; i < N; i++) {
            if(S[i] == '1' && K) {
                S[i] = '0';
                K -= 1;
            }
        }
        std::cout << S << '\n';
    } else {
        std::string ans(N - K, '0');
        std::cout << ans << '\n';
    }
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
