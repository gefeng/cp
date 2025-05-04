#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, X, Y;
    std::cin >> N >> M >> X >> Y;

    X -= 1;
    Y -= 1;

    auto output = [](int x, int y) {
        std::cout << x + 1 << ' ' << y + 1 << '\n';
    };
    
    std::vector<std::vector<int>> vis(N, std::vector<int>(M, 0));

    output(X, Y);
    vis[X][Y] = 1;
    
    X = 0;
    output(X, Y);
    vis[X][Y] = 1;
    
    for(int i = 0; i < N; i++) {
        if(i % 2 == 0) {
            for(int j = 0; j < M; j++) {
                if(vis[i][j]) {
                    continue;
                }
                output(i, j);
                vis[i][j] = 1;
            }    
        } else {
            for(int j = M - 1; j >= 0; j--) {
                if(vis[i][j]) {
                    continue;
                }
                output(i, j);
                vis[i][j] = 1;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
