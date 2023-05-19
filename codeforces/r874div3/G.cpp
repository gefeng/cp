#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int dfs(std::vector<std::vector<std::pair<int, int>>>& G, int v, int p, int e, std::vector<int>& ans) {
    int cnt_1 = 0;
    int cnt_2 = 0;

    for(auto [nv, ne] : G[v]) {
        if(nv != p) {
            int res = dfs(G, nv, v, ne, ans);

            if(res == -1) {
                return -1;
            }

            if(res == 1) {
                cnt_1 += 1;
            } else if(res == 2) {
                cnt_2 += 1;
            }
        }
    }

    if(p == -1) {
        if(cnt_1 == 2 && cnt_2 == 0) {
            return 0;
        }
        if(cnt_2 == 1 && cnt_1 == 0) {
            return 0;
        }
        return -1;
    } else {
        if(cnt_1 == 2 && cnt_2 == 0) {
            ans.push_back(e);
            return 0;
        }

        if(cnt_2 == 1 && cnt_1 == 0) {
            ans.push_back(e);
            return 0;
        }

        if(cnt_1 == 0 && cnt_2 == 0) {
            return 1;
        }

        if(cnt_1 == 1 && cnt_2 == 0) {
            return 2; 
        }

        return -1;
    }
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<std::pair<int, int>>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, i);
        G[V].emplace_back(U, i);
    } 

    std::vector<int> ans;
    
    if(dfs(G, 0, -1, -1, ans) != -1) {
        int sz = ans.size();
        std::cout << sz << '\n';
        if(sz == 0) {
            std::cout << '\n';
        }
        for(int i = 0; i < sz; i++) {
            std::cout << ans[i] + 1 << " \n"[i == sz - 1];
        }
    } else {
        std::cout << -1 << '\n';
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
