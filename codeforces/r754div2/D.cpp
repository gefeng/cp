#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(std::vector<std::vector<int>>& G, int v, int c, std::vector<int>& color) {
    color[v] = c;
    for(int nei : G[v]) {
        if(color[nei] == -1) {
            dfs(G, nei, c ^ 1, color);
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

    std::vector<int> color(N, -1);
    dfs(G, 0, 0, color); 
    
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        cnt += color[i];
    }

    std::vector<int> b;
    std::vector<int> w;
    if(cnt < N - cnt) {
        for(int i = 1; i <= N; i++) {
            for(int j = 30; j >= 0; j--) {
                if(i & (1 << j)) {
                    if(cnt & (1 << j)) {
                        b.push_back(i);
                    } else {
                        w.push_back(i);
                    }
                    break;
                }
            }
        }
    } else {
        cnt = N - cnt;
        for(int i = 1; i <= N; i++) {
            for(int j = 30; j >= 0; j--) {
                if(i & (1 << j)) {
                    if(cnt & (1 << j)) {
                        w.push_back(i);
                    } else {
                        b.push_back(i);
                    }
                    break;
                }
            }
        }
    }

    for(int i = 0, j = 0, k = 0; i < N; i++) {
        int v = color[i] ? b[j++] : w[k++];
        std::cout << v << " \n"[i == N - 1];
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
