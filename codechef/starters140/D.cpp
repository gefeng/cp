#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

const int INF = (int)2e9;

void dfs(std::vector<std::vector<int>>& G, int v, int p, std::vector<int>& ans) {
    for(int nei : G[v]) {
        if(nei != p) {
            dfs(G, nei, v, ans);
        }
    }
    ans.push_back(v);
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
    
    std::vector<int> ans;
    int min_v = INF;
    int root = 0;
    for(int i = 0; i < N; i++) {
        if(min_v > A[i]) {
            root = i;
            min_v = A[i];
        }
    }

    dfs(G, root, -1, ans);
    ans.pop_back();
    
    int n = ans.size();
    std::cout << n << '\n';
    for(int i = 0; i < n; i++) {
        std::cout << ans[i] + 1 << " \n"[i == n - 1];
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
