#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int>(2e9);

void dfs(std::string& S, int l, int r, char c, int now, int& ans) {
    if(r - l + 1 == 1) {
        now += c == S[l] ? 0 : 1;
        ans = std::min(ans, now);
        return;
    }

    int cnt_l = 0;
    int cnt_r = 0;
    int len = (r - l + 1) >> 1;
    for(int i = 0; i < len; i++) {
        if(S[l + i] != c) {
            cnt_l += 1;
        }
        if(S[r - i] != c) {
            cnt_r += 1;
        }
    }

    dfs(S, l, l + len - 1, c + 1, now + cnt_r, ans);
    dfs(S, l + len, r, c + 1, now + cnt_l, ans);
}

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;
    
    int ans = INF;
    dfs(S, 0, N - 1, 'a', 0, ans);

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
