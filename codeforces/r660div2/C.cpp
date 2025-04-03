#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void get_size(std::vector<std::vector<int>>& G, std::vector<int>& A, int v, int p, std::vector<int>& size) {
    size[v] = A[v];

    for(int nei : G[v]) {
        if(nei != p) {
            get_size(G, A, nei, v, size);
            size[v] += size[nei];
        }
    }
}

bool dfs(std::vector<std::vector<int>>& G, std::vector<int>& B,  std::vector<int>& size, int v, int p, int64_t ub, std::vector<int>& save_good) {
    // x + y = tot
    // x - y = B[v]
    // 2x = tot + b[v];

    int64_t tot = size[v];
    int64_t c = tot + B[v];
    if(c < 0 || c % 2 != 0) {
        return false;
    }

    int64_t good = c / 2;
    int64_t bad = tot - good;
    if(bad < 0 || good > ub) {
        return false;
    }

    save_good[v] = good;

    int64_t sum = 0;
    for(int nei : G[v]) {
        if(nei != p) {
            if(!dfs(G, B, size, nei, v, good, save_good)) {
                return false;
            }
            sum += save_good[nei];  
        }
    } 

    return sum <= good;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> B(N);
    std::vector<std::vector<int>> G(N);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<int> size(N, 0);
    std::vector<int> save_good(N, 0);

    get_size(G, A, 0, -1, size);

    assert(size[0] == M);

    std::cout << (dfs(G, B, size, 0, -1, M, save_good) ? "YES" : "NO") << '\n';
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
