#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int>(2e9);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::string S, T;
    std::cin >> S >> T;

    auto solve = [](std::string&& t, std::string& s) {
        int n = t.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            int d = (t[i] - s[i] + 10) % 10;
            cnt += d;
        }
        return cnt;
    };

    int ans = INF;
    for(int i = 0; i <= N - M; i++) {
        ans = std::min(ans, solve(S.substr(i, M), T));
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
