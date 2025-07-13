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
const std::string INS = "RDLU";

bool dfs_1(int N, std::vector<std::vector<std::pair<int, int>>>& A, std::vector<std::vector<int>>& end, int e_r, int e_c, int r, int c, int d, std::vector<std::string>& ans) {
    if(r == e_r && c == e_c) {
        ans[r][c] = 'X';
    } else {
        if(end[r][c]) {
            return false;
        }
        ans[r][c] = INS[d];
    }

    for(int i = 0; i < 4; i++) {
        int n_r = r + DR[i];
        int n_c = c + DC[i];
        if(n_r >= 0 && n_c >= 0 && n_r < N && n_c < N && ans[n_r][n_c] == '.' && A[n_r][n_c] == std::pair<int, int>(e_r, e_c)) {
            if(!dfs_1(N, A, end, e_r, e_c, n_r, n_c, (i + 2) % 4, ans)) {
                return false;
            }
        }
    }

    return true;
}

bool dfs_2(int N, std::vector<std::vector<std::pair<int, int>>>& A, std::vector<std::vector<int>>& end, int r, int c, std::vector<std::string>& ans) {
    for(int i = 0; i < 4; i++) {
        int n_r = r + DR[i];
        int n_c = c + DC[i];
        if(n_r >= 0 && n_c >= 0 && n_r < N && n_c < N) {
            if(A[n_r][n_c].first == -1 && ans[n_r][n_c] == '.') {
                ans[r][c] = INS[i];
                if(!dfs_2(N, A, end, n_r, n_c, ans)) {
                    return false;
                }
                return true;
            }
        }
    } 

    for(int i = 0; i < 4; i++) {
        int n_r = r + DR[i];
        int n_c = c + DC[i];
        if(n_r >= 0 && n_c >= 0 && n_r < N && n_c < N) {
            if(A[n_r][n_c].first == -1) {
                ans[r][c] = INS[i];
                return true;
            }
        }
    } 
    
    return false;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<std::pair<int, int>>> A(N, std::vector<std::pair<int, int>>(N));
    std::vector<std::vector<int>> end(N, std::vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> A[i][j].first >> A[i][j].second;
            if(A[i][j].first != -1) {
                A[i][j].first -= 1;
                A[i][j].second -= 1;
            }
            if(A[i][j].first != -1) {
                auto [x, y] = A[i][j];
                end[x][y] = 1;
            }
        }
    } 

    std::vector<std::string> ans(N, std::string(N, '.'));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(A[i][j].first == -1 && end[i][j]) {
                std::cout << "INVALID" << '\n';
                return;
            }
            if(end[i][j]) {
                if(!dfs_1(N, A, end, i, j, i, j, -1, ans)) {
                    std::cout << "INVALID" << '\n';
                    return;
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(end[i][j] && (A[i][j].first != i || A[i][j].second != j)) {
                std::cout << "INVALID" << '\n';
                return;
            }
            if(!end[i][j] && A[i][j].first != -1 && ans[i][j] == '.') {
                std::cout << "INVALID" << '\n';
                return;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(A[i][j].first == -1) {
                if(!dfs_2(N, A, end, i, j, ans)) {
                    std::cout << "INVALID" << '\n';
                    return;
                }
            }
        }
    }

    std::cout << "VALID" << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
