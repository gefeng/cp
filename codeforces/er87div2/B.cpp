#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

void run_case() {
    std::string S;
    std::cin >> S;

    int n = S.size();
    int ans = INF;
    std::array<int, 4> freq = {};

    auto is_valid = [&]() {
        for(int i = 1; i <= 3; i++) {
            if(!freq[i]) {
                return false;
            }
        }
        return true;
    };

    for(int l = 0, r = 0; r < n; r++) {
        freq[S[r] - '0'] += 1; 
        
        while(is_valid()) {
            ans = std::min(ans, r - l + 1);
            freq[S[l++] - '0'] -= 1;
        }
    }

    std::cout << (ans == INF ? 0 : ans) << '\n';
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
