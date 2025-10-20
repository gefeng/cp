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
    for(int i = 0; i < N; i++) {
        int cnt = 0;
        for(int j = 0; j < K - 1; j++) {
            if(i - j - 1 >= 0 && S[i - j - 1] == '1') {
                cnt += 1;
            }
        }
        if(cnt == 0 && S[i] == '1') {
            ans += 1; 
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
