#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <set>

using LL = long long;

constexpr LL INF = (LL)1e18;

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<std::pair<int, LL>>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;

        U -= 1;
        V -= 1;

        G[U].emplace_back(V, W);
        G[V].emplace_back(U, W);
    }

    std::vector<std::pair<std::string, LL>> ans;
    LL sum_t = 0LL;
   
    std::string s(N, '0');

    std::vector<bool> play(N, false);
    play[0] = true;
    bool ok = false;
    while(true) {
        LL min_t = INF;
        for(int v = 0; v < N; v++) {
            if(play[v]) {
                s[v] = '1';
                for(auto& nei : G[v]) {
                    if(!play[nei.first]) {
                        min_t = std::min(min_t, nei.second);
                    }
                }
            }
        }

        if(min_t == INF) {
            break;
        }
        
        if(min_t) {
            ans.emplace_back(s, min_t);
            sum_t += min_t;
        } 

        std::vector<bool> nxt_play(N, false);
        for(int v = 0; v < N; v++) {
            if(play[v]) {
                for(auto& nei : G[v]) {
                    if(!play[nei.first]) {
                        if(nei.second == min_t) {
                            nxt_play[nei.first] = true;
                        }
                        nei.second -= min_t;
                    }
                }
            }
        }

        for(int v = 0; v < N; v++) {
            if(nxt_play[v]) {
                play[v] = true;
            }
        }

        if(play[N - 1]) {
            ok = true;
            break;
        }
    }

    if(!ok) {
        std::cout << "inf" << '\n';
        return;
    }
    
    int sz = ans.size();
    std::cout << sum_t << ' ' << sz << '\n';
    for(int i = 0; i < sz; i++) {
        std::cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
