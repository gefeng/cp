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

    std::vector<std::string> ans(N, std::string(N, '.'));
    for(int i = 0; i < (N + 1) / 2; i += 2) {
        for(int j = 0; i + j <= N - 1 - i; j++) {
            ans[i][i + j] = '#';
            ans[N - 1 - i][i + j] = '#';
        } 

        for(int j = 0; i + j <= N - 1 - i; j++) {
            ans[i + j][i] = '#';
            ans[i + j][N - 1 - i] = '#';
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
