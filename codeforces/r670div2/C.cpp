#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void get_size(std::vector<std::vector<int>>& G, int v, int p, std::vector<int>& size) {
    size[v] = 1;
    for(int nei : G[v]) {
        if(nei != p) {
            get_size(G, nei, v, size);
            size[v] += size[nei];
        }
    }
}

void dfs(std::vector<std::vector<int>>& G, std::vector<int>& size, int v, int p, int& a, int& b, int& c, int& d) {
    int tot = size[0];
    bool is_c = tot - size[v] <= tot / 2;
    for(int nei : G[v]) {
        if(nei != p) {
            is_c = is_c && size[nei] <= tot / 2;
        }
    }

    if(is_c) {
        for(int nei : G[v]) {
            if(nei != p && size[nei] == tot / 2 && tot - size[nei] == tot / 2) {
                for(int u : G[nei]) {
                    if(u != v) {
                        a = nei;
                        b = u;
                        c = v;
                        d = u;
                        break;
                    }
                }   
            }
        } 

        if(a == -1) {
            if(p != -1) {
                a = p;
                b = v;
                c = p;
                d = v;
            } else {
                for(int nei : G[v]) {
                    a = v;
                    b = nei;
                    c = v;
                    d = nei;
                    break;
                }
            }
        }
        return;
    } else {
        for(int nei : G[v]) {
            if(nei != p) {
                if(size[nei] > tot / 2) {
                    dfs(G, size, nei, v, a, b, c, d);
                }
            }
        }
    }
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

    int a = -1;
    int b = -1;
    int c = -1;
    int d = -1;
    std::vector<int> size(N, 0);
    
    get_size(G, 0, -1, size);

    dfs(G, size, 0, -1, a, b, c, d);
    
    std::cout << a + 1 << ' ' << b + 1 << '\n' << c + 1 << ' ' << d + 1 << '\n';

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
