#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int>(2e9) + 10;

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::string t1 = "2025";
    std::string t2 = "2026";

    if(S.find(t2) != std::string::npos) {
        std::cout << 0 << '\n';
        return;
    }

    if(S.find(t1) == std::string::npos) {
        std::cout << 0 << '\n';
        return;
    }

    int ans = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 0; i <= N - 4; i++) {
        if(S.substr(i, 4) == t1) {
            cnt1 += 1;
        }
        if(S.substr(i, 4) == t2) {
            cnt2 += 1;
        }
    }

    ans = 1;

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
