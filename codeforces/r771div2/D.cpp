#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
#include <set>

constexpr std::array<int, 8> DR = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr std::array<int, 8> DC = {1, 0, -1, 0, 1, -1, 1, -1};

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> A(N, std::vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }

    auto check = [&](int r, int c) {
        std::array<std::pair<int, int>, 4> sq = {std::pair<int, int>(r, c), std::pair<int, int>(r + 1, c), 
            std::pair<int, int>(r, c + 1), std::pair<int, int>(r + 1, c + 1)};

        int color = 0;
        for(auto [r, c] : sq) {
            if(A[r][c]) {
                if(color == 0) {
                    color = A[r][c];
                } else {
                    if(color != A[r][c]) {
                        return 0;
                    }
                }
            }
        }

        return color;
    };

    auto paint = [&](int r, int c) {
        A[r][c] = 0;
        A[r + 1][c] = 0;
        A[r][c + 1] = 0;
        A[r + 1][c + 1] = 0;
    };

    std::vector<std::tuple<int, int, int>> ans;
    std::vector<std::vector<int>> vis(N, std::vector<int>(M, 0));
    std::queue<std::pair<int, int>> q;

    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < M - 1; j++) {
            if(A[i][j] == 0) {
                continue;
            }

            if(check(i, j)) {
                q.emplace(i, j);
                ans.emplace_back(i, j, A[i][j]);
                paint(i, j);
            }
        }
    }

    while(!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        std::array<std::pair<int, int>, 4> sq = {std::pair<int, int>(r, c), std::pair<int, int>(r + 1, c), 
            std::pair<int, int>(r, c + 1), std::pair<int, int>(r + 1, c + 1)};
        
        for(auto [r, c] : sq) {
            for(int d = 0; d < 8; d++) {
                int nr = r + DR[d];
                int nc = c + DC[d];
                if(nr >= 0 && nc >= 0 && nr < N - 1 && nc < M - 1) {
                    int color = check(nr, nc);
                    if(color) {
                        ans.emplace_back(nr, nc, color);
                        q.emplace(nr, nc); 
                        paint(nr, nc);
                    }
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(A[i][j]) {
                std::cout << -1 << '\n';
                return;
            }
        }
    }

    std::reverse(ans.begin(), ans.end());
    int size = ans.size();
    std::cout << size << '\n';
    for(auto [r, c, color] : ans) {
        std::cout << r + 1 << ' ' << c + 1 << ' ' << color << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
