#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> G(N, std::vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> G[i][j];
        }
    }

    int cnt_same = 0;
    int cnt_diff = 0;
    std::vector<std::vector<bool>> vis(N, std::vector<bool>(N, false));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(vis[i][j]) {
                continue;
            }

            if(G[i][j] == G[N - 1 - i][N - 1 - j]) {
                cnt_same += 1;
            } else {
                cnt_diff += 1;
            }
            vis[i][j] = true;
            vis[N - 1 - i][N - 1 - j] = true;
        }
    }

    if(K < cnt_diff) {
        std::cout << "NO" << '\n';
        return;
    }

    K -= cnt_diff;

    if(N % 2 == 0 && K % 2 == 1) {
        std::cout << "NO" << '\n';
        return;
    }

    std::cout << "YES" << '\n';
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
