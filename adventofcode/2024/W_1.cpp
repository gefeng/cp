#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    std::map<std::string, int> m;
    std::map<int, std::string> rm;
    std::vector<std::pair<std::string, std::string>> E;
    for(std::string S; std::getline(std::cin, S); ) {
        std::string u = S.substr(0, 2);
        std::string v = S.substr(3, 2);
        E.emplace_back(u, v);
        m[u] = 0;
        m[v] = 0;
        
    }

    int id = 0;
    for(auto& [s, v] : m) {
        v = id++;
        rm[v] = s;
    }

    int n = m.size();
    std::vector<std::vector<int>> G(n, std::vector<int>(n, 0));
    for(auto [u, v] : E) {
        G[m[u]][m[v]] = 1;
        G[m[v]][m[u]] = 1;
    }
        
    int64_t ans = 0;
    for(int a = 0; a < n; a++) {
        for(int b = a + 1; b < n; b++) {
            for(int c = b + 1; c < n; c++) {
                if(G[a][b] && G[a][c] && G[b][c]) {
                    if(rm[a][0] == 't' || rm[b][0] == 't' || rm[c][0] == 't') {
                        ans += 1;
                    }
                }                
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
