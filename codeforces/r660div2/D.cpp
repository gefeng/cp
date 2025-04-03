#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

int64_t dfs(std::vector<std::vector<int>>& g, std::vector<int>& A, int v, int64_t& ans, std::vector<std::vector<int>>& out, std::vector<int>& indegree) {
    if(g[v].empty()) {
        ans += A[v];
        return A[v];
    }

    int64_t res = A[v];
    for(int nei : g[v]) {
        int64_t ret = dfs(g, A, nei, ans, out, indegree); 
        if(ret >= 0) {
            res += ret;
            out[nei].push_back(v);
            indegree[v] += 1;
        } else {
            out[v].push_back(nei);
            indegree[nei] += 1;
        }
    }
    
    ans += res;

    return res;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<std::vector<int>> g(N);
    std::vector<int> is_root(N, 0);
    for(int i = 0; i < N; i++) {
        if(B[i] == -1) {
            is_root[i] = 1; 
        } else {
            g[B[i] - 1].push_back(i);
        }
    }

    int64_t ans = 0;
    std::vector<int> seq;
    std::vector<std::vector<int>> out(N);
    std::vector<int> indegree(N, 0);
    for(int i = 0; i < N; i++) {
        if(is_root[i]) {
            dfs(g, A, i, ans, out, indegree);
        }
    }

    std::queue<int> q;
    for(int i = 0; i < N; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    } 

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        
        seq.push_back(v);
        
        for(int nei : out[v]) {
            if(--indegree[nei] == 0) {
                q.push(nei);
            }
        }
    }

    assert(seq.size() == N);

    std::cout << ans << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << seq[i] + 1 << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
