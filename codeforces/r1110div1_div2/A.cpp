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

    if(K * 2 > N) {
        std::cout << -1 << '\n';
        return;
    }

    int ans = 0;
    for(int i = 0; i < K; i++) {
        if(S[i] == 'L') {
            ans++;
        }
        if(S[N - 1 - i] == 'R') {
            ans++;
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
