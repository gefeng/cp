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

    std::array<int, 26> vis = {};
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        if(!vis[S[i] - 'a']) {
            ans += N - i - 1;
            vis[S[i] - 'a'] = 1;
        }
    }

    for(int i = 0; i < 26; i++) {
        if(vis[i]) {
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
