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

constexpr int INF = (int)2e9;

int id = 0;
std::map<std::string, int> M;
std::set<std::pair<int, int>> E;
std::map<int, std::set<int>> G;

bool bridge(std::map<int, std::set<int>>& g, int v, int p, int& time, 
        std::vector<int>& save_t, std::vector<int>& min_t, int& bv, int& bu) {
    save_t[v] = time++;
    for(int nv : g[v]) {
        if(nv == p) {
            continue;
        }

        if(save_t[nv] != INF) {
            min_t[v] = std::min(min_t[v], save_t[nv]);
        } else {
            if(bridge(g, nv, v, time, save_t, min_t, bv, bu)) {
                return true; 
            }
            min_t[v] = std::min(min_t[v], min_t[nv]);
            if(min_t[nv] > save_t[v]) {
                bv = v;
                bu = nv;
                return true;
            }
        }
    }

    return false;
}

int dfs(std::map<int, std::set<int>>& g, std::vector<int>& vis, int v) {
    vis[v] = 1;
    int res = 1;
    for(int nv : g[v]) {
        if(!vis[nv]) {
            res += dfs(g, vis, nv);
        }
    }
    return res;
}

void run_case1() {
    std::vector<std::pair<int, int>> e(E.begin(), E.end());
    int n = e.size();

    auto find_group = [&]() {
        int64_t res = 1;
        std::vector<int> vis(id, 0);
        for(int i = 0; i < id; i++) {
            if(!vis[i]) {
                res *= dfs(G, vis, i); 
            } 
        }

        return res;
    };
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            auto [v1, u1] = e[i];
            auto [v2, u2] = e[j];

            G[v1].erase(u1);
            G[u1].erase(v1);
            G[v2].erase(u2);
            G[u2].erase(v2);
            
            int bv = -1;
            int bu = -1;
            int time = 1;
            std::vector<int> min_t(n, INF);
            std::vector<int> save_t(n, INF);
            for(int k = 0; k < n; k++) {
                if(k != i && k != j) {
                    if(bridge(G, k, -1, time, save_t, min_t, bv, bu)) {
                        std::cout << bv << ' ' << bu << '\n';
                        G[bv].erase(bu);
                        G[bu].erase(bv);
                        std::cout << find_group() << '\n';
                        return;
                    }
                    break;
                }
            }

            G[v1].insert(u1);
            G[u1].insert(v1);
            G[v2].insert(u2);
            G[u2].insert(v2);
        } 
    } 
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string S;
    while(std::getline(std::cin, S)) {
        int n = S.size();
        int i = 0;
        std::string from = "";
        while(S[i] != ':') {
            from.push_back(S[i++]);
        }

        if(M.find(from) == M.end()) {
            M[from] = id++;
        }

        while(i < n) {
            while(i < n && (S[i] == ':' || S[i] == ' ')) {
                i += 1;
            }
            
            std::string to = "";
            while(i < n && S[i] != ' ' && S[i] != ':') {
                to.push_back(S[i++]);
            }

            if(M.find(to) == M.end()) {
                M[to] = id++;
            }

            if(E.find({M[from], M[to]}) == E.end() && E.find({M[to], M[from]}) == E.end()) {
                E.emplace(M[from], M[to]);
            }
            
            G[M[from]].insert(M[to]);
            G[M[to]].insert(M[from]);
        }
    }

    run_case1();
}
