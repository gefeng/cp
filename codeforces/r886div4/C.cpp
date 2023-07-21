#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::vector<std::string> G(8);
    for(int i = 0; i < 8; i++) {
        std::cin >> G[i];
    }

    std::string ans = "";
    for(int c = 0; c < 8; c++) {
        for(int r = 0; r < 8; r++) {
            if(G[r][c] != '.') {
                ans.push_back(G[r][c]);
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
