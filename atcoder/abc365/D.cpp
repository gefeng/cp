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

    std::string S;
    std::cin >> S;

    std::vector<int> a(N);
    for(int i = 0; i < N; i++) {
        if(S[i] == 'R') {
            a[i] = 0;
        } else if(S[i] == 'P') {
            a[i] = 1;
        } else {
            a[i] = 2;
        }
    }

    auto win = [](int x) {
        if(x == 0) {
            return 1;
        } 
        if(x == 1) {
            return 2; 
        }
        return 0;
    };

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(3, -1));
    dp[1][a[0]] = 0; 
    dp[1][win(a[0])] = 1;
     
    for(int i = 2; i <= N; i++) {
        int v = a[i - 1];
        for(int j = 0; j < 3; j++) {
            if(dp[i - 1][j] != -1 && v != j) {
                dp[i][v] = std::max(dp[i][v], dp[i - 1][j]);
            }
            
            int x = win(v);
            if(dp[i - 1][j] != -1 && x != j) {
                dp[i][x] = std::max(dp[i][x], dp[i - 1][j] + 1);
            }
        }
    }

    int ans = *std::max_element(dp[N].begin(), dp[N].end());
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
