#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm> 
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> A(N);
    std::vector<std::string> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> vis(N, std::vector<int>(M, 0));
    std::vector<std::vector<int>> head(N, std::vector<int>(M, 0));
    std::vector<std::vector<int>> dist(N, std::vector<int>(M, 0));
    std::vector<std::vector<int>> size(N, std::vector<int>(M, 0));
    int max_v = 0;
    int max_b = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(!vis[i][j]) {
                int r = i;
                int c = j;
                std::set<std::pair<int, int>> s;
                std::vector<std::pair<int, int>> path;
                while(!vis[r][c] && s.find({r, c}) == s.end()) {
                    s.emplace(r, c);
                    path.emplace_back(r, c);
                    if(A[r][c] == 'L') {
                        c -= 1;
                    } else if(A[r][c] == 'R') {
                        c += 1;
                    } else if(A[r][c] == 'U') {
                        r -= 1;
                    } else {
                        r += 1;
                    }
                }

                int h = -1;
                if(vis[r][c]) {
                    h = head[r][c];
                    int k = path.size() - 1;
                    int d = dist[r][c] + 1;
                    while(k >= 0) {
                        auto [x, y] = path[k];
                        dist[x][y] = d++;
                        k -= 1;
                    }
                } else {
                    h = r * M + c;
                    
                    int k = path.size() - 1;
                    int d = 1;
                    while(true) {
                        auto [x, y] = path[k];
                        max_v += 1;
                        size[r][c] += 1;
                        if(x * M + y == h) {
                            break;
                        }
                        dist[x][y] = d++;
                        k -= 1;
                    }
                    k -= 1;
                    
                    d = 1;
                    while(k >= 0) {
                        auto [x, y] = path[k];
                        dist[x][y] = d++;
                        k -= 1;
                    }
                }

                for(auto [x, y] : s) {
                    vis[x][y] = 1;                    
                    head[x][y] = h;
                }
            }
        }
    }

    std::map<int, std::set<int>> m;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(B[i][j] == '0') {
                int h = head[i][j];
                int d = dist[i][j] % size[h / M][h % M];
                m[h].insert(d);
            }
        }
    }

    for(auto& [h, s] : m) {
        int len = size[h / M][h % M];
        max_b += std::min(len, int(s.size()));
    }

    std::cout << max_v << ' ' << max_b << '\n';
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
