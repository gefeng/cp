#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(int H, int W, std::vector<std::vector<int64_t>>& A, int r, int c, int64_t& ans) {
    if(r == H) {
        int64_t sum = 0;
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                if(A[i][j] != -1) {
                    sum ^= A[i][j];
                }
            }
        }
        ans = std::max(ans, sum);
        return;
    }

    if(c == W) {
        dfs(H, W, A, r + 1, 0, ans);
        return;
    }

    dfs(H, W, A, r, c + 1, ans);
    if(A[r][c] != -1 && c + 1 < W && A[r][c + 1] != -1) {
        int64_t a = A[r][c];
        int64_t b = A[r][c + 1];
        A[r][c] = -1;
        A[r][c + 1] = -1;
        dfs(H, W, A, r, c + 1, ans);
        A[r][c] = a;
        A[r][c + 1] = b;
    }

    if(A[r][c] != -1 && r + 1 < H && A[r + 1][c] != -1) {
        int64_t a = A[r][c];
        int64_t b = A[r + 1][c];
        A[r][c] = -1;
        A[r + 1][c] = -1;
        dfs(H, W, A, r, c + 1, ans);
        A[r][c] = a;
        A[r + 1][c] = b;
    }
}

void run_case() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::vector<int64_t>> A(H, std::vector<int64_t>(W, 0));
    
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            std::cin >> A[i][j];
        }
    }

    int64_t ans = 0;
    dfs(H, W, A, 0, 0, ans);

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
