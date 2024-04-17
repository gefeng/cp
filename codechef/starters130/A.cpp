#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    int ans = 0;
    int cnt = 0;
    for(int i = 1; i < N; i++) {
        if(S[i] == S[i - 1]) {
            cnt += 1;
        }
    }

    ans = cnt;
    for(int i = 0; i < N; i++) {
        S[i] = S[i] == '0' ? '1' : '0';
    }
    
    cnt = 0;
    for(int i = 1; i < N; i++) {
        if(S[i] == S[i - 1]) {
            cnt += 1;
        }
    }

    ans = std::min(ans, cnt);

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
