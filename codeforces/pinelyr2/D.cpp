#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> G(N);
    for(int i = 0; i < N; i++) {
        std::cin >> G[i];
    }

    std::vector<int> cnt_row(N, 0);
    std::vector<int> cnt_col(M, 0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(G[i][j] != '.') {
                cnt_row[i] += 1;
                cnt_col[j] += 1;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(cnt_row[i] % 2 == 1) {
            std::cout << -1 << '\n';
            return;
        }
    }

    for(int i = 0; i < M; i++) {
        if(cnt_col[i] % 2 == 1) {
            std::cout << -1 << '\n';
            return;
        }
    }

    cnt_row = std::vector<int>(N, 0);
    cnt_col = std::vector<int>(M, 0);
    std::vector<std::string> ans(N, std::string(M, '.'));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(G[i][j] == 'L' || G[i][j] == 'U') {
                ans[i][j] = 'B';
                cnt_row[i] += 1;
                cnt_col[j] += 1;
            } else if(G[i][j] == 'R' || G[i][j] == 'D') {
                ans[i][j] = 'W';
                cnt_row[i] -= 1;
                cnt_col[j] -= 1;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(cnt_row[i] > 0 && G[i][j] == 'U') {
                ans[i][j] = 'W';
                ans[i + 1][j] = 'B';
                cnt_row[i] -= 2;
                cnt_row[i + 1] += 2;
            }
        }
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(cnt_col[i] > 0 && G[j][i] == 'L') {
                ans[j][i] = 'W';
                ans[j][i + 1] = 'B';
                cnt_col[i] -= 2;
                cnt_col[i + 1] += 2;
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << '\n';
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
