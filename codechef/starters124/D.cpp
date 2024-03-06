#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

void dfs1(std::vector<std::vector<int>>& G, int v, int p, int d, int& max_d, std::vector<int>& depth) {
    depth[v] = d;

    max_d = std::max(max_d, d);
    
    for(int nei : G[v]) {
        if(nei != p) {
            dfs1(G, nei, v, d + 1, max_d, depth);
        }
    }
}

void dfs2(std::vector<std::vector<int>>& G, std::vector<int>& depth, std::vector<int>& set_p, 
        int v, int p, std::map<int, int>& m, std::vector<int>& score) {
    int s = 0;
    int cnt_set_c = 0;
    for(int nei : G[v]) {
        if(nei == p) {
            continue;
        }

        std::map<int, int> rhs;
        dfs2(G, depth, set_p, nei, v, rhs, score);

        cnt_set_c += set_p[nei] ? 1 : 0;
        int r = score[nei];
        
        if(rhs.size() > m.size()) {
            std::swap(m, rhs);
            std::swap(s, r);
        }

        for(auto& [k, f] : rhs) {
            if(m[k] == 1) {
                s -= 1;
            }

            m[k] += f;
            if(m[k] == 1) {
                s += 1;
            }
        }
    }

    score[v] = s + (cnt_set_c == 1 ? 1 : 0);

    for(int nei: G[v]) {
        if(nei != p && set_p[nei]) {
            m[depth[nei]] += 1;
        }
    }
}

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<int> depth(N, -1);
    int max_d = 0;
    dfs1(G, 0, -1, 0, max_d, depth);

    std::vector<int> has_p(max_d + 1, 0);
    std::vector<int> set_p(N, 0);
    std::vector<int> score(N, 0);
    int do_dfs = 0;
    for(int i = 0; i < Q; i++) {
        int T, X;
        std::cin >> T >> X;
        X -= 1;
        if(T == 1) {
            if(!do_dfs) {
                std::map<int, int> m;
                dfs2(G, depth, set_p, 0, -1, m, score);
                do_dfs = 1;
            }
            std::cout << score[X] << '\n';
        } else {
            set_p[X] ^= 1;
        }
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
