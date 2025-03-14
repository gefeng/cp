#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <tuple>

constexpr int MAX = 20;

void dfs(int L, int R, int x , int k, std::vector<std::pair<int, int>>& seg) {
    int p_2 = int(std::pow(2, k));
    int y = x + p_2;
    
    if(x >= L && y <= R) {
        seg.emplace_back(x, y); 
        return;
    }

    if(x >= R || y <= L) {
        return;
    }

    dfs(L, R, x, k - 1, seg);
    dfs(L, R, x + p_2 / 2, k - 1, seg);
}

void run_case() {
    int L_1, R_1, L_2, R_2;
    std::cin >> L_1 >> R_1 >> L_2 >> R_2;
    
    std::vector<std::pair<int, int>> seg_x;
    std::vector<std::pair<int, int>> seg_y;
    
    dfs(L_1, R_1, 0, MAX, seg_x);
    dfs(L_2, R_2, 0, MAX, seg_y);
    
    int ans = 0;
    for(auto [l_x, r_x] : seg_x) {
        int len_x = r_x - l_x;
        for(auto [l_y, r_y] : seg_y) {
            int len_y = r_y - l_y;
            ans += len_x >= len_y ? len_x / len_y : len_y / len_x;
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
