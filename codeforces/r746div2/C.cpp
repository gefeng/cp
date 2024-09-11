#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

int dfs1(std::vector<std::set<int>>& G, std::vector<int>& A, int t, int v, int p, std::vector<int>& save_xor) {
    save_xor[v] = A[v];
    for(int nei : G[v]) {
        if(nei != p) {
            int ret = dfs1(G, A, t, nei, v, save_xor);
            if(ret != -1) {
                return ret;
            }
            save_xor[v] ^= save_xor[nei];
        }
    }

    if(save_xor[v] == t && p != -1) {
        return v;
    }
    return -1;
}

int dfs2(std::vector<std::set<int>>& G, std::vector<int>& A, int t, int removed, int v, int p, std::vector<int>& save_xor) {
    save_xor[v] = A[v];
    for(int nei : G[v]) {
        if(nei != p && nei != removed) {
            int ret = dfs2(G, A, t, removed, nei, v, save_xor);
            if(ret != -1) {
                return ret;
            }
            save_xor[v] ^= save_xor[nei];
        }
    }    

    if(save_xor[v] == t) {
        return v;
    }
    return -1;
}

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> A(N);
    int xor_sum = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        xor_sum ^= A[i];
    }

    std::vector<std::set<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].insert(V);
        G[V].insert(U);
    }

    if(xor_sum == 0) {
        std::cout << "YES" << '\n';
        return;
    }

    if(K - 1 == 1) {
        std::cout << "NO" << '\n';
        return;
    }

    std::vector<int> save_xor(N, 0);
    int removed = dfs1(G, A, xor_sum, 0, -1, save_xor);
    if(removed != -1) {
        save_xor.assign(N, 0);
        if(dfs2(G, A, xor_sum, removed, 0, -1, save_xor) != -1) {
            std::cout << "YES" << '\n';
            return;
        }
    }
    std::cout << "NO" << '\n';
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
