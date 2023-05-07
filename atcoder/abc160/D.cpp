#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X, Y;
    std::cin >> N >> X >> Y;

    X -= 1;
    Y -= 1;

    std::vector<std::vector<int>> dist(N, std::vector<int>(N, 0));
    std::vector<int> ans(N, 0);
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            dist[i][j] = j - i;
        
            if(i <= X && j >= Y) {
                dist[i][j] = std::min(dist[i][j], X - i + j - Y + 1);
            }
            
            if(i > X && j < Y) {
                dist[i][j] = std::min(dist[i][j], i - X + Y - j + 1); 
            }

            if(i <= X && j < Y) {
                dist[i][j] = std::min(dist[i][j], X - i + Y - j + 1);
            }

            if(i > X && j >= Y) {
                dist[i][j] = std::min(dist[i][j], i - X + j - Y + 1);
            }

            ans[dist[i][j]] += 1;
        }
    }

    for(int i = 1; i < N; i++) {
        std::cout << ans[i] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
