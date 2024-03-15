#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::string> G(2);
    for(int i = 0; i < 2; i++) {
        std::cin >> G[i];
    }

    std::vector<std::vector<int>> vis(2, std::vector<int>(N, 0));
    std::queue<std::pair<int, int>> q;

    q.emplace(0, 0);
    vis[0][0] = 1;

    while(!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if(r == 1 && c == N - 1) {
            std::cout << "Yes" << '\n';
            return;
        }

        if(c + 1 < N && G[r][c + 1] == '>' && !vis[r][c + 2]) {
            q.emplace(r, c + 2);
            vis[r][c + 2] = 1;
        }

        if(r + 1 < 2 && G[r + 1][c] == '>' && !vis[r + 1][c + 1]) {
            q.emplace(r + 1, c + 1);
            vis[r + 1][c + 1] = 1;
        }

        if(r - 1 >= 0 && G[r - 1][c] == '>' && !vis[r - 1][c + 1]) {
            q.emplace(r - 1, c + 1);
            vis[r - 1][c + 1] = 1;
        }
    }

    std::cout << "No" << '\n';
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
