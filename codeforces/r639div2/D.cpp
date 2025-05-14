#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};

void dfs(int N, int M, std::vector<std::string>& A, std::vector<std::vector<int>>& vis, int r, int c) {
    vis[r][c] = 1;
    
    for(int i = 0; i < 4; i++) {
        int nr = r + DR[i];
        int nc = c + DC[i];
        if(nr >= 0 && nr < N && nc >= 0 && nc < M && A[nr][nc] == '#' && !vis[nr][nc]) {
            dfs(N, M, A, vis, nr, nc);;
        }
    }
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        int seen = 0;
        for(int j = 0; j < M; ) {
            int k = j;
            while(j < M && A[i][j] == A[i][k]) {
                j += 1;
            }
            if(A[i][k] == '#') {
                if(seen) {
                    std::cout << -1 << '\n';
                    return;
                }
                seen = 1;
            }
        }
    }

    for(int i = 0; i < M; i++) {
        int seen = 0;
        for(int j = 0; j < N; ) {
            int k = j;
            while(j < N && A[j][i] == A[k][i]) {
                j += 1;
            }
            if(A[k][i] == '#') {
                if(seen) {
                    std::cout << -1 << '\n';
                    return;
                }
                seen = 1;
            }
        }
    }

    std::vector<int> cnt_row(N, 0);
    std::vector<int> cnt_col(M, 0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(A[i][j] == '#') {
                cnt_row[i] += 1;
                cnt_col[j] += 1;
            }
        }
    }

    std::vector<int> black_row(N, 0);
    std::vector<int> black_col(M, 0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(A[i][j] == '#') {
                black_row[i] = 1;
                black_col[j] = 1;
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(!black_row[i] && !black_col[j]) {
                cnt_row[i] += 1;
                cnt_col[j] += 1;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(cnt_row[i] == 0 || cnt_col[j] == 0) {
                std::cout << -1 << '\n';
                return;
            }
        }
    }

    int ans = 0;
    std::vector<std::vector<int>> vis(N, std::vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(!vis[i][j] && A[i][j] == '#') {
                ans += 1; 
                dfs(N, M, A, vis, i, j);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(!vis[i][j] && A[i][j] == '#') {
                std::cout << -1 << '\n';
                return;
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
