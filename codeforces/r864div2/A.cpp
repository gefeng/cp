#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    int X1, Y1, X2, Y2;
    std::cin >> X1 >> Y1 >> X2 >> Y2;
    X1 -= 1;
    X2 -= 1;
    Y1 -= 1;
    Y2 -= 1;

    auto solve = [&](int x, int y) {
        int res = 4;
        std::array<int, 4> dr = {0, 1, 0, -1};
        std::array<int, 4> dc = {1, 0, -1, 0};
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dr[i]; 
            int ny = y + dc[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) {
                res -= 1;
            }
        }

        return res;
    };
    
    std::cout << std::min(solve(X1, Y1), solve(X2, Y2)) << '\n';
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
