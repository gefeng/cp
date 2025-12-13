#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::vector<int>> ans(N, std::vector<int>(N, 0));
    
    ans[0][(N - 1) / 2] = 1;
    int r = 0;
    int c = (N - 1) / 2;
    int k = 1;
    for(int _ = 0; _ < N * N - 1; _++) {
        int nr = (r - 1 + N) % N;
        int nc = (c + 1) % N;
        if(ans[nr][nc] != 0) {
            nr = (r + 1) % N;
            nc = c;
        }
        r = nr;
        c = nc;
        k = k + 1;
        ans[r][c] = k;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cout << ans[i][j] << " \n"[j == N - 1];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
