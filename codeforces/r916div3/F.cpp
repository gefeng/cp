#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

void dfs(std::vector<std::vector<int>>& G, int v, std::vector<int>& dp, std::vector<int>& save_size) {
    std::vector<std::pair<int, int>> s;
    for(int nei : G[v]) {
        dfs(G, nei, dp, save_size);
        s.emplace_back(save_size[nei], nei);
    }

    if(s.empty()) {
        return;
    }

    std::sort(s.begin(), s.end());
    
    int size = s.size();
    int sum = 0;
    for(int i = 0; i < size - 1; i++) {
        sum += s[i].first;
    }

    int res = 0;
    if(sum <= s.back().first) {
        res += sum;
        int left = (save_size[s.back().second] - sum) / 2;
        res += std::min(left, dp[s.back().second]);
    } else {
        std::priority_queue<int> pq;
        for(int i = 0; i < size; i++) {
            pq.push(s[i].first);
        }
        while(pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            res += 1;
            if(--x > 0) {
                pq.push(x);
            }
            if(--y > 0) {
                pq.push(y);
            }
        }
    }

    dp[v] = res;
}

int get_size(std::vector<std::vector<int>>& G, int v, std::vector<int>& save_size) {
    save_size[v] = 1;
    for(int nei : G[v]) {
        save_size[v] += get_size(G, nei, save_size);
    } 
    return save_size[v];
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> G(N);
    for(int i = 1; i < N; i++) {
        int P;
        std::cin >> P;
        P -= 1;
        G[P].push_back(i);
    }


    std::vector<int> dp(N, 0);
    std::vector<int> save_size(N, 0);

    get_size(G, 0, save_size);
    dfs(G, 0, dp, save_size);

    std::cout << dp[0] << '\n';
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
