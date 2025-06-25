#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int validate(std::vector<std::vector<int>>& G, std::vector<int>& A, int v, bool& ok) {
    int size = 1;
    for(int nei : G[v]) {
        size += validate(G, A, nei, ok);
    }
    if(A[v] >= size) {
        ok = false;
    }
    return size;
}

std::vector<int> dfs(std::vector<std::vector<int>>& G, std::vector<int>& A, int v) {
    std::vector<int> a;
    if(G[v].empty()) {
        a.push_back(v);
        return a;
    }

    for(int nei : G[v]) {
        std::vector<int> ret = dfs(G, A, nei);
        for(int x : ret) {
            if(a.size() == A[v]) {
                a.push_back(v);
            } 
            a.push_back(x);
        }
    }

    if(a.size() == A[v]) {
        a.push_back(v);
    }

    return a;
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::vector<int>> G(N);
    std::vector<int> A(N);
    int root = 0;
    for(int i = 0; i < N; i++) {
        int P;
        std::cin >> P >> A[i];
        if(P == 0) {
            root = i;
        } else {
            G[P - 1].push_back(i);
        }
    }

    bool ok = true;
    validate(G, A, root, ok);
    if(!ok) {
        std::cout << "NO" << '\n';
        return;
    }

    std::vector<int> order = dfs(G, A, root);
    std::vector<int> ans(N, 0);
    for(int i = 1; i <= N; i++) {
        ans[order[i - 1]] = i;
    } 

    std::cout << "YES" << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
