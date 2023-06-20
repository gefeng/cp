#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

constexpr int INF = (int)2e9;

const std::array<int, 2> DR = {0, 1};
const std::array<int, 2> DC = {1, 0};

void bfs(int N, int M, std::vector<std::vector<bool>>& can_reach, std::vector<std::pair<int, int>> source, int d) {
    std::queue<std::pair<int, int>> q;
    
    for(auto& p : source) {
        q.emplace(p.first, p.second);
        can_reach[p.first][p.second] = true;
    }

    int step = 0;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            std::pair<int, int> cur = q.front();
            q.pop();
            
            int r = cur.first;
            int c = cur.second;

            for(int i = 0; i < 2; i++) {
                int nr = r + DR[i];
                int nc = c + DC[i];
                if(nr >= 0 && nc >= 0 && nr <= N && nc <= M && !can_reach[nr][nc]) {
                    can_reach[nr][nc] = true;
                    q.emplace(nr, nc);
                }
            }
        }

        if(++step == d) {
            break;
        }
    }
} 

void run_case() {
    int N, M, R;
    std::cin >> N >> M >> R;

    std::vector<std::vector<int>> A(R);
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < 3; j++) {
            int X;
            std::cin >> X;
            A[i].push_back(X);
        }
    }

    auto cmp = [](const auto& a, const auto& b) {
        return a[0] < b[0];
    };

    std::sort(A.begin(), A.end(), cmp);

    std::vector<std::pair<int, int>> pos;
    pos.emplace_back(0, 0);

    int t = 0;
    int ans = INF;
    for(int i = 0; i < R; ) {
        int j = i;
        int d = A[j][0] - t;
        std::vector<bool> cover_r(N + 1, false);
        std::vector<bool> cover_c(M + 1, false);
        while(i < R && A[j][0] == A[i][0]) {
            if(A[i][1] == 1) {
                cover_r[A[i][2]] = true; 
            } else {
                cover_c[A[i][2]] = true;
            }
            i += 1;
        }

        for(auto& p : pos) {
            int r = p.first;
            int c = p.second;
            if(N - r + M - c < d || (N - r + M - c == d && !cover_r[N] && !cover_c[M])) {
                ans = std::min(ans, t + N - r + M - c);
            }
        }

        if(ans != INF) {
            break;
        }

        std::vector<std::pair<int, int>> nxt;  
        std::vector<std::vector<bool>> vis(N + 1, std::vector<bool>(M + 1, false));
        bfs(N, M, vis, pos, d);

        for(int r = 0; r <= N; r++) {
            for(int c = 0; c <= M; c++) {
                if(!cover_r[r] && !cover_c[c] && vis[r][c]) {
                    nxt.emplace_back(r, c);
                }
            }
        } 

        if(nxt.empty()) {
            std::cout << -1 << '\n';
            return;
        }

        std::swap(pos, nxt);
        t = A[j][0];
    }

    for(auto& p : pos) {
        int r = p.first;
        int c = p.second;
        ans = std::min(ans, t + N - r + M - c);
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
