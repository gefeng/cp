#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int K;
    std::cin >> K;
    
    std::vector<std::vector<int>> ans(3, std::vector<int>(3, K));
    
    int b = -1;
    for(int i = 30; i >= 0; i--) {
        if(K & (1 << i)) {
            b = i + 1; 
            break;
        }
    }

    int x = (1 << b) | K;
    
    ans[0][0] = x;
    ans[0][1] = 1 << b;
    ans[1][1] = x;
    ans[2][1] = x;

    std::cout << 3 << ' ' << 3 << '\n';
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << ans[i][j] << " \n"[j == 2];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
