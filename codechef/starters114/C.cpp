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

    if(N == 2) {
        std::cout << -1 << '\n';
        return;
    }

    if(N == 1) {
        std::cout << 1 << '\n';
        return;
    }

    std::vector<std::vector<int>> ans(N, std::vector<int>(N, 0));

    ans[0][0] = 1;
    ans[0][1] = 2;
    ans[0][2] = 4;
    
    ans[1][0] = 6;
    ans[1][1] = 8;
    ans[1][2] = 3;

    ans[2][0] = 5;
    ans[2][1] = 7;
    ans[2][2] = 9;

    for(int k = 4; k <= N; k++) {
        int cnt = 2 * k - 1;
        int cur = k * k - cnt + 1;
        for(int i = 0; i < k; i++) {
            ans[i][k - 1] = cur++;
        }
        for(int i = k - 2; i >= 0; i--) {
            ans[k - 1][i] = cur++;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cout << ans[i][j] << " \n"[j == N - 1];
        }
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
