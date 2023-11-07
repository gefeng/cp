#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

bool dfs(int N, std::string& R, std::string& C, std::vector<int> set_c, std::vector<std::string>& G, int r) {
    if(r == N) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(G[j][i] != '.') {
                    if(C[i] != G[j][i]) {
                        return false;
                    }
                    break;
                }
            }
        }
        
        for(int i = 0; i < N; i++) {
            std::array<int, 3> cnt = {};
            for(int j = 0; j < N; j++) {
                if(G[j][i] != '.') {
                    cnt[G[j][i] - 'A'] += 1;
                }
            }

            for(int x : cnt) {
                if(x != 1) {
                    return false;
                }
            }
        }
        return true;
    } 

    std::vector<int> save(set_c);
    for(int i = 0; i < (1 << N); i++) {
        if(__builtin_popcount(i) == 3) {
            std::vector<int> pos;
            for(int j = 0; j < N; j++) {
                if(i & (1 << j)) {
                    pos.push_back(j);
                }
            }

            char c1 = R[r] == 'A' ? 'B' : 'A';
            char c2 = R[r] == 'A' ? 'C' : (R[r] == 'B' ? 'C' : 'B');
            G[r][pos[0]] = R[r]; 
            G[r][pos[1]] = c1;
            G[r][pos[2]] = c2;

            bool ok = true;
            for(int p : pos) {
                if(!set_c[p] && C[p] != G[r][p]) {
                    ok = false;
                    break;
                }
                set_c[p] = 1;
            }
            
            if(ok) {
                if(dfs(N, R, C, set_c, G, r + 1)) {
                    return true;
                }
            }

            set_c = save;

            G[r][pos[1]] = c2;
            G[r][pos[2]] = c1;
            
            ok = true;
            for(int p : pos) {
                if(!set_c[p] && C[p] != G[r][p]) {
                    ok = false;
                    break;
                }
                set_c[p] = 1;
            }
            if(ok) {
                if(dfs(N, R, C, set_c, G, r + 1)) {
                    return true;
                }
            }

            for(int p : pos) {
                G[r][p] = '.';
            }
            
            set_c = save;
        }
    }

    return false;
}

void run_case() {
    int N;
    std::cin >> N;

    std::string R, C;
    std::cin >> R >> C;

    std::vector<std::string> G(N, std::string(N, '.'));
    std::vector<int> set_c(N, 0);
    
    if(dfs(N, R, C, set_c, G, 0)) {
        std::cout << "Yes" << '\n';
        for(int i = 0; i < N; i++) {
            std::cout << G[i] << '\n';
        } 
    } else {
        std::cout << "No" << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
