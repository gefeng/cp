#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

constexpr int64_t INF = (int64_t)1e18;

void dfs(std::vector<std::vector<int>>& G, std::vector<int>& A, int K, std::vector<int64_t>& dp, std::map<int64_t, int>& m, int v) {
    std::set<int> nxt;

    for(int nei : G[v]) {
        int64_t t = dp[v] + ((A[nei] - (dp[v] % K) + K) % K);
        if(t > dp[nei]) {
            if(--m[dp[nei]] == 0) {
                m.erase(dp[nei]);
            }

            dp[nei] = t;
            m[dp[nei]] += 1;

            nxt.insert(nei);
        }
    } 
    
    for(int nei : nxt) {
        dfs(G, A, K, dp, m, nei);
    }
}

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> G(N);
    std::vector<int> indegree(N, 0);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        indegree[V] += 1;
    }

    std::queue<int> q;
    std::vector<int64_t> dp(N, -INF);
    std::vector<int> start;
    for(int i = 0; i < N; i++) {
        if(indegree[i] == 0) {
            q.push(i);
            start.push_back(i);
            dp[i] = A[i];
        }
    }

    std::sort(start.begin(), start.end(), [&](int i, int j) {
        return A[i] < A[j];
    });

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        for(int nei : G[v]) {
            dp[nei] = std::max(dp[nei], dp[v] + ((A[nei] - (dp[v] % K) + K) % K));

            if(--indegree[nei] == 0) {
                q.push(nei);
            }
        }
    }

    int64_t ans = 0;
    std::map<int64_t, int> m;
    for(int i = 0; i < N; i++) {
        m[dp[i]] += 1;
    }

    ans = m.rbegin()->first - A[start[0]];

    int sz = start.size();
    for(int i = 1; i < sz; i++) {
        int cur = start[i];
        int pre = start[i - 1];

        if(--m[dp[pre]] == 0) {
            m.erase(dp[pre]); 
        }

        dp[pre] += K;
        m[dp[pre]] += 1;

        dfs(G, A, K, dp, m, pre);

        ans = std::min(ans, m.rbegin()->first - A[cur]);
    }

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
