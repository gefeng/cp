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
    
    std::string s = "";
    for(int i = 0; i < N; i++) {
        s.append("BAN");
    }

    int l = 0;
    int r = N * 3 - 1;
    std::vector<std::pair<int, int>> ans;
    while(l <= r) {
        while(l <= r && s[l] != 'B') {
            l += 1;
        }
        while(l <= r && s[r] != 'N') {
            r -= 1;
        }
        
        if(l < r && s[r] == 'N' && s[l] == 'B') {
            ans.emplace_back(l, r);
            l += 1;
            r -= 1;
        } else {
            break;
        }
    }

    int m = ans.size();
    std::cout << m << '\n';
    for(int i = 0; i < m; i++) {
        std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
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
