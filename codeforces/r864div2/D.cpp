#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using LL = long long;

struct cmp {
    bool operator() (std::pair<int, int> a, std::pair<int, int> b) const {
        if(a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};

std::pair<int, LL> dfs1(std::vector<std::set<int>>& G, std::vector<int>& A, 
    int v, int p, std::vector<int>& save_p, std::vector<int>& save_s, std::vector<LL>& save_i, 
    std::vector<std::set<std::pair<int, int>, cmp>>& save_w) {
    save_p[v] = p;

    int sum_w = 1;
    LL sum_i = A[v];
    for(int nei : G[v]) {
        if(nei != p) {
            std::pair<int, LL> res = dfs1(G, A, nei, v, save_p, save_s, save_i, save_w);
            sum_w += res.first;
            sum_i += res.second;

            save_w[v].emplace(res.first, nei);
        }
    }

    save_i[v] = sum_i;
    save_s[v] = sum_w;

    return {sum_w, sum_i};
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
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


    std::vector<int> save_p(N, -1);
    std::vector<LL> save_i(N, 0);
    std::vector<int> save_s(N, 0);
    std::vector<std::set<std::pair<int, int>, cmp>> save_w(N);

    auto remove = [&](int v, int p) {
        G[p].erase(v);
        G[v].erase(p);
        save_i[p] -= save_i[v];
        save_s[p] -= save_s[v];
        save_w[p].erase({save_s[v], v});
        save_p[v] = -1;
    };

    auto append = [&](int v, int p) {
        G[p].insert(v);
        G[v].insert(p);
        save_i[p] += save_i[v]; 
        save_s[p] += save_s[v];
        save_w[p].emplace(save_s[v], v);
        save_p[v] = p;
    };

    dfs1(G, A, 0, -1, save_p, save_s, save_i, save_w);

    for(int i = 0; i < M; i++) {
        int T, X;
        std::cin >> T >> X;
        X -= 1;
        if(T == 1) {
            std::cout << save_i[X] << '\n';
        } else {
            if(save_w[X].empty()) {
                continue;
            }

            int p = save_p[X];
            
            // remove from parent
            remove(X, p);
            
            // remove from X
            std::pair<int, int> son = *save_w[X].rbegin();
            remove(son.second, X);
            
            append(X, son.second);

            append(son.second, p);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
