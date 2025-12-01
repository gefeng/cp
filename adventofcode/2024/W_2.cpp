#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

constexpr int MAX_D = 13;

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

    std::vector<int> removed(n, 0);
    for(int i = 0; i < n; i++) {
        if(removed[i]) {
            continue;
        }
        
        std::vector<int> neis;
        for(int j = 0; j < n; j++) {
            if(i != j && G[i][j]) {
                neis.push_back(j);
            }
        }

        for(int u : neis) {
            std::set<int> clique;
            clique.insert(i);
            for(int v : neis) {
                if(v != u) {
                    clique.insert(v);
                }
            }
            
            bool good = true;
            for(int v : neis) {
                if(v == u) {
                    continue;
                }

                int cnt = 0;
                for(int j = 0; j < n; j++) {
                    if(v != j && G[v][j]) {
                        if(clique.find(j) == clique.end()) {
                            cnt +=1 ;
                        }
                    }
                }
                if(cnt > 1) {
                    good = false;
                    break;
                }
            }

            if(good) {
                std::vector<std::string> ans;
                for(int v : clique) {
                    ans.push_back(rm[v]);
                }
                std::sort(ans.begin(), ans.end());
                
                std::string key = "";
                for(std::string s : ans) {
                    key.append(s + ',');
                }
                std::cout << key << '\n';
            }
        }

        removed[i] = 1;
        for(int v : neis) {
            removed[v] = 1;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
