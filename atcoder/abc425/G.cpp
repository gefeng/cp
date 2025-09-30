#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

int64_t dfs(std::vector<std::array<int, 2>>& trie, int now, int k, int r, std::map<std::pair<int, int>, int64_t>& dp) {
    if(trie[now][0] == -1 && trie[now][1] == -1) {
        return 0;
    }
    
    if(dp.find({now, r}) != dp.end()) {
        return dp[{now, r}];
    }

    int64_t res = 0;
    if(trie[now][0] != -1) {
        if(k) {
            res += dfs(trie, trie[now][0], k - 1, std::min(r, (1 << k) - 1), dp);
        }
    } else {
        res += static_cast<int64_t>(1 << k) * std::min(r + 1, 1 << k);
        if(k) {
            res += dfs(trie, trie[now][1], k - 1, std::min(r, (1 << k) - 1), dp);
        }
    }

    if(r >= (1 << k)) {
        if(trie[now][1] != -1) {
            if(k) {
                res += dfs(trie, trie[now][1], k - 1, r - (1 << k), dp);
            }
        } else {
            res += static_cast<int64_t>(1 << k) * (r - (1 << k) + 1);
            if(k) {
                res += dfs(trie, trie[now][0], k - 1, r - (1 << k), dp);
            }
        }
    }

    return dp[{now, r}] = res;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int id = 1;
    std::vector<std::array<int, 2>> trie;
    trie.push_back({-1, -1});

    for(int i = 0; i < N; i++) {
        int now = 0;
        for(int j = 29; j >= 0; j--) {
            int b = A[i] & (1 << j) ? 1 : 0;
            if(trie[now][b] == -1) {
                trie.push_back({-1, -1});
                trie[now][b] = id++;
            }
            now = trie[now][b];
        }
    }

    std::map<std::pair<int, int>, int64_t> dp;
    int64_t ans = dfs(trie, 0, 29, M - 1, dp);

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
