#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 500;

void run_case() {
    int K;
    std::cin >> K;
    
    std::vector<std::pair<int, int>> ans;
    
    int x = 0;
    int y = 0;
    while(K) {
        int f = -1;
        for(int a = MAX; a > 1; a--) {
            if(a * (a - 1) / 2 <= K) {
                f = a; 
                break;
            } 
        }

        for(int i = 0; i < f; i++) {
            ans.emplace_back(x++, y);
        } 
        y++;
        K -= f * (f - 1) / 2;
    }

    assert(K == 0);

    int n = ans.size();
    std::cout << n << '\n';
    for(int i = 0; i < n; i++) {
        std::cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
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
