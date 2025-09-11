#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <ranges>

constexpr int MAX = static_cast<int>(2e5);

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

    int m = static_cast<int>(sqrt(N));
    std::vector<int> a;
    std::vector<int> cnt(m, 0);
    for(int i = 0; i < min_d; i++) {
        int v = lv[i];
        if(v >= m) {
            a.push_back(v);
        } else {
            cnt[v] += 1; 
        }
    }

    for(int i = 1; i < m; i++) {
        if(cnt[i]) {
            int c = cnt[i];
            int p = 1;
            while(c >= p) {
                a.push_back(p * i);
                c -= p;
                p *= 2;
            }
            if(c) {
                a.push_back(c * i);
            }
        } 
    }

    int n = a.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(K + 1, 0));
    dp[0][K] = 1;
    
    int sum = 0;
    int ans = -1;
    for(int i = 1; i <= n; i++) {
        int v = a[i - 1];
        for(int j = 0; j <= K; j++) {
            if(!dp[i - 1][j]) {
                continue;
            }
            int ones = N - sum - j;
            if(j >= v) {
                dp[i][j - v] = 1;
            }
            if(ones >= v) {
                dp[i][j] = 1;
            }
        } 
        sum += v;
    }

    for(int i = 0; i <= K; i++) {
        if(dp[n][i]) {
            ans = min_d;
        }
    }

    ans = ans == -1 ? min_d - 1 : ans;

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
