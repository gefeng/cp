#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int dfs(std::vector<std::vector<int>>& G, std::string& S, int v, int& ans) {
    std::vector<int> a;
    for(int nei : G[v]) {
        int t = dfs(G, S, nei, ans); 
        a.push_back(t);
    }
    
    int type = 0;
    if(S[v] == 'P') {
        for(int t : a) {
            if(t == 1) {
                ans += 1;
            }
        } 
        type = 2;
    } else if(S[v] == 'S') {
        for(int t : a) {
            if(t == 2) {
                ans += 1;
            }
        }
        type = 1;
    } else {
        int cnt_p = 0;
        int cnt_s = 0;
        for(int t : a) {
            if(t == 1) {
                cnt_s += 1;
            } else if(t == 2) {
                cnt_p += 1;
            }
        }
        
        if(cnt_p == 0 && cnt_s == 0) {
            type = 0; 
        } else if(cnt_p == 0) {
            type = 1;
        } else if(cnt_s == 0) {
            type = 2;
        } else {
            ans += std::min(cnt_p, cnt_s);
            if(cnt_p == cnt_s) {
                type = 0;
            } else if(cnt_p > cnt_s) {
                type = 2;
            } else {
                type = 1;
            }
        }
    }

    return type;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> G(N);
    for(int i = 1; i < N; i++) {
        int P;
        std::cin >> P;
        P -= 1;
        G[P].push_back(i);
    }

    std::string S;
    std::cin >> S;

    int ans = 0;

    dfs(G, S, 0, ans);

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
