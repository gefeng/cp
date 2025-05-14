#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int MAX = int(5e4);
constexpr int INF = int(2e9);

void dfs(std::vector<int>& prefix, int now, std::vector<int>& dp, std::vector<int>& vis) {
    if(vis[now]) {
        return;
    }

    vis[now] = 1;

    if(now < prefix.front()) {
        dp[now] = 1;
        return;
    }

    auto it = std::upper_bound(prefix.begin(), prefix.end(), now); 
    int last = it - prefix.begin();
    for(int i = 0; i < last; i++) {
        dfs(prefix, now % prefix[i], dp, vis);
    }
}

void run_case() {
    int N, X, Y;
    std::cin >> N >> X >> Y;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> ans;
    std::vector<int> prefix;
    int min_v = INF;
    for(int i = 0; i < N; i++) {
        prefix.push_back(A[i]);
        min_v = std::min(min_v, A[i]);

        if(Y >= min_v) {
            continue;
        }
        
        std::sort(prefix.begin(), prefix.end());
        
        prefix.erase(std::unique(prefix.begin(), prefix.end()), prefix.end());

        int n = prefix.size();
        std::vector<int> dp(MAX + 1, 0);
        std::vector<int> vis(MAX + 1, 0);
        for(int i = 0; i < n; i++) {
            dfs(prefix, X, dp, vis);
        }
        
        if(Y < min_v && dp[Y]) {
            ans.push_back(i);
        }
    }

    int size = ans.size();
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] + 1 << " \n"[i == size - 1];
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
