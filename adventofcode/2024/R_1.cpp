#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int MAX = 1024;
constexpr int N = 71;
constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};

int next_int(std::string& S, int& p) {
    int n = S.size();
    int x = 0;
    while(p < n && !isdigit(S[p])) {
        p += 1;
    }
    while(p < n && isdigit(S[p])) {
        x = x * 10 + S[p++] - '0';
    }
    return x;
}

void run_case() {
    std::vector<std::pair<int, int>> A;
    for(std::string S; std::getline(std::cin, S); ) {
        int p = 0;
        int x = next_int(S, p);
        int y = next_int(S, p);
        A.emplace_back(x, y);
    }
    
    std::vector<std::string> g(N, std::string(N, '.'));
    for(int i = 0; i < MAX; i++) {
        auto [r, c] = A[i]; 
        g[r][c] = '#';
    }

    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> vis(N, std::vector<int>(N, 0));
    
    q.emplace(0, 0);
    vis[0][0] = 1;
    
    int d = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            auto [r, c] = q.front();
            q.pop();

            if(r == N - 1 && c == N - 1) {
                std::cout << d << '\n';
                return;
            }
            
            for(int i = 0; i < 4; i++) {
                int nr = r + DR[i];
                int nc = c + DC[i];
                if(nr >= 0 && nc >= 0 && nr < N && nc < N && !vis[nr][nc] && g[nr][nc] == '.') {
                    vis[nr][nc] = 1; 
                    q.emplace(nr, nc);
                }
            } 
        }
        d += 1;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
