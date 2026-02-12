#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <deque>
#include <tuple>

constexpr int INF = static_cast<int>(2e9) + 10;
constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto can_grow = [&](int r, int c) {
        if(A[r][c] == '#') {
            return false;
        }
        for(int d = 0; d < 4;  d++) {
            int nr = r + DR[d];
            int nc = c + DC[d];
            if(nr >= 0 && nc >= 0 && nr < N && nc < M && A[nr][nc] == '#') {
                return false;
            }
        }
        return true;
    };

    std::deque<std::pair<int, int>> deq;
    std::vector<std::vector<int>> dist(N, std::vector<int>(M, INF));
    std::vector<std::vector<std::pair<int, int>>> pre(N, std::vector<std::pair<int, int>>(M, {-1, -1}));
    for(int r = 0; r < N; r++) {
        if(A[r][0] == '#') {
            deq.emplace_front(r, 0);
            dist[r][0] = 0;
        } else {
            if(can_grow(r, 0)) {
                deq.emplace_back(r, 0);
                dist[r][0] = 1;
            }
        }
    }

    bool found = false;
    while(!deq.empty()) {
        auto [r, c] = deq.front();
        deq.pop_front();

        if(c == M - 1) {
            std::pair<int, int> now{r, c}; 
            while(now.first != -1) {
                A[now.first][now.second] = '#';
                now = pre[now.first][now.second];
            }
            found = true;
            break;
        }

        for(int dc = -1; dc < 2; dc += 2) {
            for(int dr = -1; dr < 2; dr += 2) {
                int nr = r + dr;
                int nc = c + dc;
                if(nr >= 0 && nc >= 0 && nr < N && nc < M) {
                    if(A[nr][nc] == '#') {
                        if(dist[r][c] < dist[nr][nc]) {
                            deq.emplace_front(nr, nc);
                            dist[nr][nc] = dist[r][c];
                            pre[nr][nc] = {r, c};
                        }
                    } else if(can_grow(nr, nc)) {
                        if(dist[r][c] + 1 < dist[nr][nc]) {
                            deq.emplace_back(nr, nc);
                            dist[nr][nc] = dist[r][c] + 1;
                            pre[nr][nc] = {r, c};
                        }
                    }
                }
            }
        }
    }

    if(!found) {
        std::cout << "NO" << '\n';
        return;
    }

    std::cout << "YES" << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << A[i] << '\n';
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
