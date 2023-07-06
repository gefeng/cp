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

    std::array<int, 2> ans = {};
    int server = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] - 'A' == server) {
            ans[S[i] - 'A'] += 1; 
        } else {
            server ^= 1;
        }
    }

    std::cout << ans[0] << ' ' << ans[1] << '\n';
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
