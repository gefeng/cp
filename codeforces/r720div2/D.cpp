#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void dfs1(std::vector<std::set<int>>& G, int v, int p, std::vector<std::array<int, 4>>& ans) {
    std::vector<int> neis(G[v].begin(), G[v].end());
    for(int nei : neis) {
        if(nei == p) {
            continue;
        }
        dfs1(G, nei, v, ans);
    }
    
    int cnt_c = G[v].size() - (p == -1 ? 0 : 1);
    if(cnt_c <= 1) {
        return;
    }
    if(cnt_c == 2) {
        if(p != -1) {
            ans.push_back({p, v, -1, -1});
            G[p].erase(v);
            G[v].erase(p);
        }  
    } else {
        if(p != -1) {
            ans.push_back({p, v, -1, -1});
            G[p].erase(v);
            G[v].erase(p);
        }

        while(G[v].size() > 2) {
            int u = *G[v].begin();
            ans.push_back({v, u, -1, -1});
            G[u].erase(v);
            G[v].erase(u);
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::set<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].insert(V);
        G[V].insert(U);
    }

    std::vector<std::array<int, 4>> ans;
    dfs1(G, 0, -1, ans);
    
    std::vector<int> vis(N, 0);
    int ep1 = -1;
    int ep2 = -1;
    for(int i = 0; i < N; i++) {
        if(G[i].size() == 0) {
            ep1 = i;
            ep2 = i;
            vis[i] = 1;
            break;
        }
        if(G[i].size() == 1) {
            ep1 = i;
            ep2 = i;
            while(!vis[ep2]) {
                vis[ep2] = 1;
                for(int nei : G[ep2]) {
                    if(!vis[nei]) {
                        ep2 = nei;
                        break;
                    }
                }
            }
            break;
        }
    }

    for(int i = 0, j = 0; i < N; i++) {
        if(vis[i]) {
            continue;
        }
        
        if(G[i].size() <= 1) {
            int l = i;
            int r = i;
            while(!vis[r]) {
                vis[r] = 1;
                for(int nei : G[r]) {
                    if(!vis[nei]) {
                        r = nei;
                        break;
                    }
                }
            }
            ans[j][2] = ep2;
            ans[j][3] = l;
            j += 1;
            ep2 = r;
        }
    }

    for(int i = 0; i < N; i++) {
        if(!vis[i]) {
            std::cout << i << ' ' << G[i].size() << '\n';
        } 
    }

    int k = ans.size();
    std::cout << k << '\n';
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < 4; j++) {
            std::cout << ans[i][j] + 1 << " \n"[j == 3];
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
