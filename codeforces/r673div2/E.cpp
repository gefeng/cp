#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(std::vector<std::array<int, 2>>& trie, std::vector<std::vector<int>>& data, int v, int b, std::vector<std::vector<int64_t>>& dp) {
    if(b < 0 || (trie[v][0] == -1 && trie[v][1] == -1)) {
        return;
    }
    
    if(trie[v][0] != -1) {
        dfs(trie, data, trie[v][0], b - 1, dp);
    }

    if(trie[v][1] != -1) {
        dfs(trie, data, trie[v][1], b - 1, dp);
    }

    if(trie[v][0] != -1 && trie[v][1] != -1) {
        std::vector<int>& lhs = data[trie[v][0]];
        std::vector<int>& rhs = data[trie[v][1]];
        int n = lhs.size();
        int m = rhs.size();
        int64_t cnt = 0;
        for(int i = 0, j = 0; i < n; i++) {
            while(j < m && rhs[j] < lhs[i]) {
                j += 1;
            }  
            cnt += j;
        }
        dp[0][b] += cnt;
        
        cnt = 0;
        for(int i = 0, j = 0; i < m; i++) {
            while(j < n && lhs[j] < rhs[i]) {
                j += 1;
            }
            cnt += j;
        }

        dp[1][b] += cnt;
    }
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::array<int, 2>> trie;
    std::vector<std::vector<int>> data;
    std::vector<std::vector<int64_t>> dp(2, std::vector<int64_t>(30, 0));
    int id = 0;
    
    trie.push_back({-1, -1});
    data.emplace_back();
    id++; 
    
    for(int j = 0; j < N; j++) {
        int x = A[j];
        int v = 0;
        for(int i = 29; i >= 0; i--) {
            int b = (x & (1 << i)) ? 1 : 0;
            if(trie[v][b] == -1) {
                trie[v][b] = id++;
                trie.push_back({-1, -1}); 
                data.emplace_back();
            }
            v = trie[v][b];
            data[v].push_back(j); 
        }
    }

    dfs(trie, data, 0, 29, dp);

    int64_t cnt_inv = 0;
    int x = 0;
    for(int i = 0; i < 30; i++) {
        if(dp[1][i] < dp[0][i]) {
            x |= 1 << i;
        }
        cnt_inv += std::min(dp[0][i], dp[1][i]);
    }

    std::cout << cnt_inv << ' ' << x << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
