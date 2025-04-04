#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

void run_case() {
    int N;
    std::cin >> N;

    std::string S, T;
    std::cin >> S >> T;

    if(S == T) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<int> to(26, -1);
    std::vector<int> indegree(26, 0);
    for(int i = 0; i < N; i++) {
        int u = S[i] - 'a';
        int v = T[i] - 'a';
        if(to[u] != -1 && to[u] != v) {
            std::cout << -1 << '\n';
            return;
        }
        
        if(to[u] == -1) {
            to[u] = v;
            indegree[v] += 1;
        }
    }

    int ans = 0;
    std::vector<int> head(26, -1);
    std::vector<int> in_cycle(26, 0);
    for(int i = 0; i < 26; i++) {
        if(head[i] != -1) {
            continue;
        } 

        int v = i;
        std::vector<int> vis(26, 0);
        while(v != -1 && !vis[v]) {
            vis[v] = 1;
            v = to[v];
        }
        
        if(v != -1 && head[v] == -1) {
            int st = v;
            int len = 0;
            bool no_branch = true;
            vis.assign(26, 0);
            while(!vis[v]) {
                vis[v] = 1;
                in_cycle[v] = 1;
                head[v] = st;
                if(indegree[v] > 1) {
                    no_branch = false;
                }
                v = to[v];
                len += 1;
            }
        
            if(len > 1) {
                ans += no_branch ? len + 1 : len;
            }
        }
    }

    bool all_cycle = true;
    for(int i = 0; i < 26; i++) {
        if(!in_cycle[i]) {
            all_cycle = false; 
            if(to[i] != -1 && to[i] != i) {
                ans += 1;
            }
        }
    }
    if(all_cycle) {
        std::cout << -1 << '\n';
        return;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
