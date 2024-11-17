#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int dfs(int n, std::vector<int>& cards, int a, int b, int t, std::vector<std::vector<std::vector<int>>>& dp) {
    int c = (1 << n) - 1;
    c ^= a;
    c ^= b;

    if(dp[t][a][b] != -1) {
        return dp[t][a][b];
    }

    std::vector<int> table;
    std::vector<int> hands;
    for(int i = 0; i < n; i++) {
        if(c & (1 << i)) {
            table.push_back(i);
        }
    }
    
    int res = 0;
    if(t == 0) {
        for(int i = 0; i < n; i++) {
            if(a & (1 << i)) {
                hands.push_back(i);
            }
        }
        for(int i : hands) {
            for(int j : table) {
                if(cards[j] >= cards[i]) {
                    break;
                }
                int na = a ^ (1 << i) ^ (1 << j);
                if(!dfs(n, cards, na, b, t ^ 1, dp)) {
                    res = 1;
                }
            }
            
            if(!dfs(n, cards, a ^ (1 << i), b, t ^ 1, dp)) {
                res = 1;
            }
        }
    } else {
        for(int i = 0; i < n; i++) {
            if(b & (1 << i)) {
                hands.push_back(i);
            }
        }
        for(int i : hands) {
            for(int j : table) {
                if(cards[j] >= cards[i]) {
                    break;
                }
                int nb = b ^ (1 << i) ^ (1 << j);
                if(!dfs(n, cards, a, nb, t ^ 1, dp)) {
                    res = 1;
                }
            }

            if(!dfs(n, cards, a, b ^ (1 << i), t ^ 1, dp)) {
                res = 1;
            }
        }
    }

    return dp[t][a][b] = res;
}

void run_case() {
    int N, M, L;
    std::cin >> N >> M >> L;
    
    int n = N + M + L;
    std::vector<std::pair<int, int>> A(n);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
        A[i].second = 0;
    }

    for(int i = N; i < N + M; i++) {
        std::cin >> A[i].first;
        A[i].second = 1;
    }

    for(int i = N + M; i < n; i++) {
        std::cin >> A[i].first;
        A[i].second = 2;
    }

    std::sort(A.begin(), A.end());
    
    int a = 0;
    int b = 0;
    std::vector<int> cards(n);
    for(int i = 0; i < n; i++) {
        cards[i] = A[i].first;
        if(A[i].second == 0) {
            a ^= 1 << i;
        }
        if(A[i].second == 1) {
            b ^= 1 << i;
        }
    }

    std::vector<std::vector<std::vector<int>>> dp(2, std::vector<std::vector<int>>(1 << n, std::vector<int>(1 << n, -1)));
    
    int res = dfs(n, cards, a, b, 0, dp);

    std::cout << (res == 1 ? "Takahashi" : "Aoki") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
