#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int dfs(std::vector<std::vector<int>>& G, std::string& S, int v) {
    char c = S[v];

    if(G[v][0] == -1 && G[v][1] == -1) {
        return 0;
    }
    
    int l = -1;
    int r = -1;
    if(G[v][0] != -1) {
        l = dfs(G, S, G[v][0]) + (c != 'L' ? 1 : 0);
    }

    if(G[v][1] != -1) {
        r = dfs(G, S, G[v][1]) + (c != 'R' ? 1 : 0);
    }

    if(l == -1) {
        return r;
    }
    if(r == -1) {
        return l;
    }

    return std::min(l, r);
}

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::vector<std::vector<int>> G(N, std::vector<int>(2, -1));
    for(int i = 0; i < N; i++) {
        int L, R;
        std::cin >> L >> R;

        L -= 1;
        R -= 1;
        
        if(L != -1) {
            G[i][0] = L;
        }
        if(R != -1) {
            G[i][1] = R;
        }
    }

    std::cout << dfs(G, S, 0) << '\n';
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
