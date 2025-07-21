#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> ans;
    
    std::vector<int> p_8;
    for(int i = 8; i <= N; i *= 8) {
        p_8.push_back(i);
    }

    auto is_power_8 = [&](int x) {
        for(int y : p_8) {
            if(x == y) {
                return true;
            }
        }
        return false;
    };

    for(int i = 3; i < N; i++) {
        if(!is_power_8(i)) {
            ans.emplace_back(i, i + 1); 
        }
    }

    if(p_8.empty()) {
        int x = N;
        while(x != 1) {
            x = (x + 1) / 2;
            ans.emplace_back(N, 2);
        }
    } else {
        if(!is_power_8(N)) {
            ans.emplace_back(N, *p_8.rbegin());
            ans.emplace_back(N, 8);
        }

        for(int i = p_8.size() - 1; i > 0; i--) {
            ans.emplace_back(p_8[i], p_8[i - 1]);
            ans.emplace_back(p_8[i], 8);
        }

        for(int i = 0; i < 3; i++) {
            ans.emplace_back(8, 2);
        }
    }

    int size = ans.size();
    assert(size <= N + 5);
    
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
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
