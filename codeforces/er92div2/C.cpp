#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    std::string S;
    std::cin >> S;

    int n = S.size();
    int ans = n;
    for(char c = '0'; c <= '9'; c++) {
        ans = std::min(ans, int(n - std::ranges::count(S, c)));
    }

    std::vector<std::vector<int>> pos(10);
    for(int i = 0; i < n; i++) {
        pos[S[i] - '0'].push_back(i);
    }

    for(int a = 0; a < 10; a++) {
        if(pos[a].empty()) {
            continue;
        }
        for(int b = 0; b < 10; b++) {
            if(pos[b].empty()) {
                continue;
            }

            int m = pos[a].size();
            int len = 1;
            int pre = pos[a][0];
            for(int i = 1; i < m; i++) {
                auto it = std::ranges::upper_bound(pos[b], pre);
                if(it != pos[b].end() && *it < pos[a][i]) {
                    len += 2;
                    pre = pos[a][i];
                }
            }
            auto it = std::ranges::upper_bound(pos[b], pre);
            if(it != pos[b].end()) {
                len += 1;
            }
            if(len % 2 == 0) {
                ans = std::min(ans, n - len);
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
