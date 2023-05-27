#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    std::vector<std::string> G; 
    std::string S;
    while(std::getline(std::cin, S)) {
        G.push_back(S); 
    }

    int n = G.size();
    int m = G[0].size();

    std::vector<std::vector<LL>> vis(n, std::vector<LL>(m, 1LL));
    
    for(int i = 0; i < n; i++) {
        std::vector<int> s;
        for(int j = 0; j < m; j++) {
            while(!s.empty() && G[i][s.back()] < G[i][j]) {
                s.pop_back();
            }

            int pre = s.empty() ? 0 : s.back();
            
            vis[i][j] *= j - pre;

            s.push_back(j);
        }

        s = std::vector<int>();
        for(int j = m - 1; j >= 0; j--) {
            while(!s.empty() && G[i][s.back()] < G[i][j]) {
                s.pop_back();
            }

            int pre = s.empty() ? m - 1 : s.back();

            vis[i][j] *= pre - j;

            s.push_back(j);
        }
    }

    for(int i = 0; i < m; i++) {
        std::vector<int> s;
        
        for(int j = 0; j < n; j++) {
            while(!s.empty() && G[s.back()][i] < G[j][i]) {
                s.pop_back();
            }

            int pre = s.empty() ? 0 : s.back();

            vis[j][i] *= pre - j;

            s.push_back(j);
        }

        s = std::vector<int>();
        for(int j = n - 1; j >= 0; j--) {
            while(!s.empty() && G[s.back()][i] < G[j][i]) {
                s.pop_back();
            }

            int pre = s.empty() ? n - 1 : s.back();

            vis[j][i] *= j - pre;

            s.push_back(j);
        }
    } 

    LL ans = 0LL;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans = std::max(ans, vis[i][j]);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
