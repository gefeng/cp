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
    int M, D;
    std::cin >> M >> D;

    std::string S;
    std::cin >> S;
    
    int n = S.size();
    int ans = 0;
    
    std::vector<int> close(n, INF);
    for(int i = n - 1; i >= 0; i--) {
        if(S[i] == 'G') {
            close[i] = i;
        } else {
            close[i] = i + 1 < n ? close[i + 1] : INF;
        }
    }

    int pre = INF;
    for(int i = 0; i < n; i++) {
        if(S[i] == 'G') {
            pre = i;
        } 
        if(std::min(std::abs(i - pre), std::abs(close[i] - i)) > D) {
            ans++;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
