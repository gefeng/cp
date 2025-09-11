#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> G(N);
    for(int i = 1; i < N; i++) {
        int P;
        std::cin >> P;
        P -= 1;
        G[P].push_back(i);
    }

    std::queue<int> q;
    std::vector<int> lv;
    int min_d = N;
    int d = 0;
    q.push(0);
    while(!q.empty()) {
        int size = q.size();
        lv.push_back(size);
        d += 1;    
        while(size--) {
            int v = q.front();
            q.pop();
            if(G[v].size() == 0) {
                min_d = std::min(min_d, d);
            }
            for(int nei : G[v]) {
                q.push(nei);
            }
        }
    }

    int n = lv.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(K + 1, 0));
    dp[0][K] = 1;
    
    int sum = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= K; j++) {
            if(!dp[i - 1][j]) {
                continue;
            }
            int ones = N - sum - j;
            if(j >= lv[i - 1]) {
                dp[i][j - lv[i - 1]] = 1;
                ans = i;
            }
            if(ones >= lv[i - 1]) {
                dp[i][j] = 1;
                ans = i;
            }
        } 
        sum += lv[i - 1];
    }

    ans = std::min(ans, min_d);

    std::cout << ans << '\n';
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
