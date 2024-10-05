#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

bool dfs(std::vector<std::vector<int>>& G, std::vector<int>& color, int v, int c) {
    color[v] = c;
    for(int nei : G[v]) {
        if(color[nei] == -1) {
            if(!dfs(G, color, nei, c ^ 1)) {
                return false;
            }
        } else {
            if(color[nei] == c) {
                return false;
            }
        }
    }

    return true;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<int> color(N, -1);
    bool bipartite = dfs(G, color, 0, 0);
    
    if(bipartite) {
        std::cout << "Bob" << std::endl;
        std::vector<std::vector<int>> which(2);
        std::set<int> s;
        for(int i = 0; i < N; i++) {
            which[color[i]].push_back(i);
            s.insert(i);
        }

        for(int i = 0; i < N; i++) {
            std::array<int, 2> C;
            std::cin >> C[0] >> C[1];
            if(C[0] > C[1]) {
                std::swap(C[0], C[1]);
            }

            int v = -1;
            int c = -1;
            for(int x : C) {
                if(x != 3 && !which[x - 1].empty()) {
                    v = which[x - 1].back();
                    c = x;
                    which[x - 1].pop_back();
                    break;
                }
            }

            if(c == -1) {
                v = *s.begin();   
                c = 3;
            }

            s.erase(v);

            std::cout << v + 1 << ' ' << c << std::endl;
        }
    } else {
        std::cout << "Alice" << std::endl;
        for(int i = 0; i < N; i++) {
            std::cout << "1 2" << std::endl;
            int V, C;
            std::cin >> V;
            if(V == -1) {
                return;
            }
            std::cin >> C;
            if(C == -1) {
                return;
            }
            std::cout << std::endl;
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
