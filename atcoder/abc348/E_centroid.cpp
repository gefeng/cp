#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs1(std::vector<std::vector<int>>& G, std::vector<int>& A, int v, int p, std::vector<int64_t>& save) {
    save[v] = A[v]; 
    for(int nei : G[v]) {
        if(nei != p) {
            dfs1(G, A, nei, v, save);
            save[v] += save[nei];
        }
    }
}

void dfs2(std::vector<std::vector<int>>& G, int64_t sum, int v, int p, std::vector<int64_t>& save, int& centroid) {
    bool is_centroid = true;
    for(int nei : G[v]) {
        if(nei != p) {
            if(save[nei] > sum / 2) {
                is_centroid = false;
                dfs2(G, sum, nei, v, save, centroid);
            }
        }
    }

    if(is_centroid) {
        centroid = v;
    }
}

int64_t dfs3(std::vector<std::vector<int>>& G, std::vector<int>& A, int v, int p, int d) {
    int64_t res = (int64_t)A[v] * d;

    for(int nei : G[v]) {
        if(nei != p) {
            res += dfs3(G, A, nei, v, d + 1); 
        }
    }

    return res;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<int> A(N);
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum += A[i];
    }

    std::vector<int64_t> save(N, (int64_t)0);
    dfs1(G, A, 0, -1, save);

    int centroid = 0;
    dfs2(G, sum, 0, -1, save, centroid);

    std::cout << dfs3(G, A, centroid, -1, 0) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
