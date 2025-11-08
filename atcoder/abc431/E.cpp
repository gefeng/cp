#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath> #include <array>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

constexpr int INF = static_cast<int>(2e9);

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};

void run_case() {
    int H, W;
    std::cin >> H >> W;
    
    std::vector<std::string> A(H);
    for(int i = 0; i < H; i++) {
        std::cin >> A[i];
    }

    auto reflect = [&](int s, int d) {
        int rd = 0;
        if(s == 1) {
            if(d < 2) {
                rd = d ^ 1; 
            } else {
                rd = ((d - 2) ^ 1) + 2;
            }
        } else {
            if(d == 0) {
                rd = 3;
            } else if(d == 3) {
                rd = 0;
            } else if(d == 1) {
                rd = 2;
            } else {
                rd = 1;
            }
        }
        return rd;
    };

    std::deque<std::tuple<int, int, int, int>> q;
    std::vector<std::vector<std::vector<std::vector<int>>>> best(3, 
            std::vector<std::vector<std::vector<int>>>(4, std::vector<std::vector<int>>(H, std::vector<int>(W, INF))));

    best[A[0][0] - 'A'][0][0][0] = 0;
    q.emplace_back(0, 0, 0, A[0][0] - 'A');

    while(!q.empty()) {
        auto [r, c, d, s] = q.front();
        q.pop_front();

        for(int ns = 0; ns < 3; ns++) {
            if(best[ns][d][r][c] > best[s][d][r][c] + 1) {
                best[ns][d][r][c] = best[s][d][r][c] + 1;
                q.emplace_back(r, c, d, ns);
            }
        }

        if(s == 0) {
            int nr = r + DR[d];
            int nc = c + DC[d];
            if(nr >= 0 && nc >= 0 && nr < H && nc < W) {
                int ns = A[nr][nc] - 'A';
                if(best[ns][d][nr][nc] > best[s][d][r][c]) {
                    best[ns][d][nr][nc] = best[s][d][r][c];
                    q.emplace_front(nr, nc, d, ns);
                }
            }
        } else {
            int nd = reflect(s, d);
            int nr = r + DR[nd];
            int nc = c + DC[nd];
            if(nr >= 0 && nc >= 0 && nr < H && nc < W) {
                int ns = A[nr][nc] - 'A';
                if(best[ns][nd][nr][nc] > best[s][d][r][c]) {
                    best[ns][nd][nr][nc] = best[s][d][r][c];
                    q.emplace_front(nr, nc, nd, ns);
                }
            }
        }
    }

    int ans = std::min(best[0][0][H - 1][W - 1], best[1][1][H - 1][W - 1]);

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
