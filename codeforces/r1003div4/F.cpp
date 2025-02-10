#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void dfs(std::vector<std::vector<int>>& G, std::vector<int>& A, int v, int p, std::string& ans) {
    std::set<int> seen;
    for(int nei : G[v]) {
        if(nei != p) {
            if(A[nei] == A[v]) {
                ans[A[v] - 1] = '1';
            }
            if(p != -1 && A[p] == A[nei]) {
                ans[A[nei] - 1] = '1';
            }
            if(seen.find(A[nei]) != seen.end()) {
                ans[A[nei] - 1] = '1';
            }
            seen.insert(A[nei]);
            dfs(G, A, nei, v, ans);
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::string ans(N, '0');
    dfs(G, A, 0, -1, ans);
    
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
