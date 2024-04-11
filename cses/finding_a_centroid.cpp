#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

void dfs1(std::vector<std::vector<int>>& G, int v, int p, std::vector<int>& size) {
    size[v] = 1;
    for(int nei : G[v]) {
        if(nei != p) {
            dfs1(G, nei, v, size);
            size[v] += size[nei];
        }
    } 
}

void dfs2(int N, std::vector<std::vector<int>>& G, int v, int p, std::vector<int>& size, int& centroid) {
    bool ok = true;
    for(int nei : G[v]) {
        if(nei != p) {
            if(size[nei] > N / 2) {
                ok = false;
                dfs2(N, G, nei, v, size, centroid);
            } 
        }
    }

    if(ok) {
        centroid = v;
    }
    return;
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

    int centroid = 0;
    std::vector<int> size(N, 0);
    dfs1(G, 0, -1, size);
    dfs2(N, G, 0, -1, size, centroid);

    std::cout << centroid + 1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    
    run_case();
}
