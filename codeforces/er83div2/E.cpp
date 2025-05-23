#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    // dp_1[i][j] = x denotes merge [i, j] to x 
    std::vector<std::vector<int>> dp_1(N, std::vector<int>(N, INF));
    for(int i = 0; i < N; i++) {
        dp_1[i][i] = A[i];
    }

    for(int i = N - 1; i >= 0; i--) {
        for(int j = i + 1; j < N; j++) {
            for(int k = i; k < j; k++) {
                if(dp_1[i][k] != INF && dp_1[i][k] == dp_1[k + 1][j]) {
                    dp_1[i][j] = dp_1[i][k] + 1;
                }
            }
        }
    }

    std::vector<int> dp_2(N + 1, INF);
    dp_2[0] = 0;
    
    for(int i = 1; i <= N; i++) {
        for(int j = i; j > 0; j--) {
            if(dp_1[j - 1][i - 1] != INF) {
                dp_2[i] = std::min(dp_2[i], dp_2[j - 1] + 1);
            }
        } 
    }

    std::cout << dp_2[N] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
