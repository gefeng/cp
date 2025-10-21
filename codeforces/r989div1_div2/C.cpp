#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int dfs(int N, int M, std::vector<std::string>& A, std::vector<std::vector<int>>& vis, std::vector<std::vector<int>>& good, int r, int c) {
    int res = 1;
    vis[r][c] = 1;
    good[r][c] = 1;
    
    if(r - 1 >= 0 && A[r - 1][c] == 'D' && !vis[r - 1][c]) {
        res += dfs(N, M, A, vis, good, r - 1, c);
    }

    if(r + 1 < N && A[r + 1][c] == 'U' && !vis[r + 1][c]) {
        res += dfs(N, M, A, vis, good, r + 1, c);
    }

    if(c - 1 >= 0 && A[r][c - 1] == 'R' && !vis[r][c - 1]) {
        res += dfs(N, M, A, vis, good, r, c - 1);
    }

    if(c + 1 < M && A[r][c + 1] == 'L' && !vis[r][c + 1]) {
        res += dfs(N, M, A, vis, good, r, c + 1);
    }
    return res;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto is_exit = [&](int r, int c) {
        if(r == 0 && A[r][c] == 'U') {
            return true;
        }

        if(r == N - 1 && A[r][c] == 'D') {
            return true;
        }

        if(c == 0 && A[r][c] == 'L') {
            return true;
        }
        
        if(c == M - 1 && A[r][c] == 'R') {
            return true;
        }
        
        return false;
    };

    int ans = N * M;
    std::vector<std::vector<int>> vis(N, std::vector<int>(M, 0));
    std::vector<std::vector<int>> good(N, std::vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if((i == 0 || j == 0 || i == N - 1 || j == M - 1)) {
                if(!vis[i][j] && A[i][j] != '?' && is_exit(i, j)) {
                    dfs(N, M, A, vis, good, i, j);
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(A[i][j] == '?') {
                bool is_good = true;
                if(i - 1 >= 0 && (A[i - 1][j] == '?' || A[i - 1][j] == 'D' || !good[i - 1][j])) {
                    is_good = false;
                }

                if(i + 1 < N && (A[i + 1][j] == '?' || A[i + 1][j] == 'U' || !good[i + 1][j])) {
                    is_good = false;
                }

                if(j - 1 >= 0 && (A[i][j - 1] == '?' || A[i][j - 1] == 'R' || !good[i][j - 1])) {
                    is_good = false;
                }
                
                if(j + 1 < M && (A[i][j + 1] == '?' || A[i][j + 1] == 'L' || !good[i][j + 1])) {
                    is_good = false;
                }

                if(is_good) {
                    ans -= 1;
                }
            } else {
                if(good[i][j]) {
                    ans -= 1;
                }
            }
        }
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
