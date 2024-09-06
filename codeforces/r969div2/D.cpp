#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(1e9);

void dfs1(std::vector<std::vector<int>>& G, int v, int p, std::vector<int>& leaf) {
    if(p != -1 && G[v].size() == 1) {
        leaf.push_back(v);
    }

    for(int nei : G[v]) {
        if(nei != p) {
            dfs1(G, nei, v, leaf);
        }
    }
}

int dfs2(std::vector<std::vector<int>>& G, std::string& S, int v, int p, int d) {
    if(S[v] == '?') {
        return INF;
    }

    if(p != -1) {
        if(S[v] == '0' && S[p] == '1') {
            d -= 1;
        } else if(S[v] == '1' && S[p] == '0') {
            d += 1;
        }
    }

    if(p != -1 && G[v].size() == 1) {
        return d != 0 ? 1 : 0; 
    }

    int res = 0;
    for(int nei : G[v]) {
        if(nei != p) {
            int x = dfs2(G, S, nei, v, d); 
            if(x != INF) {
                res += x;
            }
        }
    }
    return res;
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

    std::string S;
    std::cin >> S;
    
    int ans = 0;
    std::vector<int> leaf;
    dfs1(G, 0, -1, leaf);
    if(S[0] == '?') {
        int left = 0;
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            if(S[i] == '?') {
                left += 1;
            }
        }

        left -= 1;
        int cnt0 = 0;
        int cnt1 = 0;
        for(int v : leaf) {
            if(S[v] == '?') {
                left -= 1;
                cnt += 1;
            } else if(S[v] == '0') {
                cnt0 += 1;
            } else {
                cnt1 += 1;
            }
        }

        if(cnt0 == cnt1 && left % 2 == 1) {
            ans = (cnt + 1) / 2 + cnt0;
        }

        for(char c = '0'; c <= '1'; c++) {
            S[0] = c;
            int res = 0;
            for(int v : leaf) {
                if(S[v] != '?' && S[v] != S[0]) {
                    res += 1;
                }
            }
            
            res += cnt / 2;
            ans = std::max(ans, res);
        }
    } else {
        int cnt = 0;
        for(int v : leaf) {
            if(S[v] == '?') {
                cnt += 1;
            } else {
                if(S[v] != S[0]) {
                    ans += 1;
                }
            }
        }
        ans += (cnt + 1) / 2;
    }

    std::cout << ans << '\n';
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
