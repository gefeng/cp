#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

std::string S = "qkj";

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::vector<int>> A(3, std::vector<int>(N, 0));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> A[i][j];
            A[i][j] -= 1;
        }
    }

    std::vector<int> dp(N, 0);
    dp[N - 1] = 1;

    std::vector<std::pair<int, int>> min_card(3);
    for(int i = 0; i < 3; i++) {
        min_card[i] = {A[i][N - 1], N - 1};
    }

    std::vector<std::pair<int, int>> to(N, {-1, -1});
    for(int i = N - 2; i >= 0; i--) {
        for(int j = 0; j < 3; j++) {
            if(A[j][i] > min_card[j].first) {
                dp[i] = 1;
                to[i] = {j, min_card[j].second};
                break;
            }
        }

        if(dp[i]) {
            for(int j = 0; j < 3; j++) {
                if(A[j][i] < min_card[j].first) {
                    min_card[j] = {A[j][i], i};
                }
            } 
        }
    }

    if(!dp[0]) {
        std::cout << "No" << '\n';
        return;
    }

    std::vector<std::pair<int, int>> ans;
    int card = 0;
    while(card != N - 1) {
        ans.emplace_back(to[card].first, to[card].second);
        card = to[card].second;
    } 

    int m = ans.size();
    std::cout << "Yes" << '\n' << m << '\n';;
    for(int i = 0; i < m; i++) {
        std::cout << S[ans[i].first] << ' ' << ans[i].second + 1 << '\n';
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
