#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

const std::array<int, 4> DR = {0, 1, 0, -1};
const std::array<int, 4> DC = {1, 0, -1, 0};

constexpr int L = 50;

void run_case() {
    std::vector<std::string> G;
    int N = 0;
    int M = 0;

    bool complete = false;
    std::string S;
    std::string T; 
    while(std::getline(std::cin, S)) {
        if(S.empty()) {
            complete = true; 
        }
        if(!complete) {
            G.push_back(S);
            M = std::max(M, (int)S.size());
        } else {
            T = S; 
        }
    }

    N = G.size(); 

    std::vector<std::pair<int, int>> rs;
    std::vector<std::pair<int, int>> cs;
    for(int i = 0; i < N; i++) {
        while(G[i].size() < M) {
            G[i].push_back(' ');
        }

        int l = -1;
        int r = -1;
        for(int j = 0; j < M; j++) {
            if(G[i][j] != ' ') {
                l = l == -1 ? j : l;
                r = j;
            } 
        }

        rs.emplace_back(l, r);
    }

    for(int i = 0; i < M; i++) {
        int l = -1;
        int r = -1;
        for(int j = 0; j < N; j++) {
            if(G[j][i] != ' ') {
                l = l == -1 ? j : l;
                r = j;
            } 
        }

        cs.emplace_back(l, r);
    }

    auto is_digit = [](char c) {
        return c >= '0' && c <= '9';
    };

    std::vector<std::pair<int, int>> instructions;
    int sz = T.size();
    for(int i = 0; i < sz; ) {
        if(is_digit(T[i])) {
            int x = 0;
            while(i < sz && is_digit(T[i])) {
                x = x * 10 + T[i] - '0';
                i += 1;
            }
            instructions.emplace_back(0, x);
        } else {
            int d = T[i] == 'R' ? 0 : 1;
            instructions.emplace_back(1, d);
            i += 1;
        }
    }

    int r = 0;
    int c = 0;
    int d = 0;
    for(int i = 0; i < M; i++) {
        if(G[0][i] == '.') {
            c = i; 
            break;
        }
    }

    for(auto& ins : instructions) {
        int t = ins.first;
        int v = ins.second;
        
        if(t == 0) {
            for(int i = 0; i < v; i++) {
                bool stop = false;
                int nr = r + DR[d];
                int nc = c + DC[d];
                int nd = d;

                if(d % 2 == 0) {
                    // moving horizontally    
                    if(d == 0 && (nc >= M || G[nr][nc] == ' ')) {
                        if(r < L) {
                            // 1 -> 4
                            nr = 2 * L + (L - 1 - r);
                            nc = 2 * L - 1; 
                            nd = 2;
                        } else if(r < 2 * L) {
                            // 3 -> 1
                            nr = L - 1;
                            nc = r - L + 2 * L;
                            nd = 3;
                        } else if(r < 3 * L) {
                            // 4 -> 1
                            nr = L - 1 - (r - 2 * L);
                            nc = 3 * L - 1;
                            nd = 2;
                        } else {
                            // 6 -> 4
                            nr = 3 * L - 1;
                            nc = r - 3 * L + L;
                            nd = 3;
                        }

                        //nc = rs[r].first; 
                        if(G[nr][nc] == '#') {
                            stop = true;
                        } else {
                            r = nr;
                            c = nc;
                            d = nd;
                        }
                    } else if(d == 2 && (nc < 0 || G[nr][nc] == ' ')) {
                        if(r < L) {
                            // 2 -> 5
                            nr = 2 * L + (L - 1 - r);
                            nc = 0;
                            nd = 0;
                        } else if(r < 2 * L) {
                            // 3 -> 5
                            nr = 2 * L; 
                            nc = r - L;
                            nd = 1;
                        } else if(r < 3 * L) {
                            // 5 -> 2
                            nr = L - 1 - (r - 2 * L); 
                            nc = L;
                            nd = 0;
                        } else  {
                            // 6 -> 2
                            nr = 0;
                            nc = r - 3 * L + L;
                            nd = 1;
                        }

                        //nc = rs[r].second;
                        if(G[nr][nc] == '#') {
                            stop = true;
                        } else {
                            r = nr;
                            c = nc;
                            d = nd;
                        }
                    } else if(G[nr][nc] == '.') {
                        r = nr;
                        c = nc;
                    } else {
                        stop = true;
                    }
                } else {
                    // moving vertically
                    if(d == 1 && (nr >= N || G[nr][nc] == ' ')) {
                        if(c >= 2 * L) {
                            // 1 -> 3
                            nr = c - 2 * L + L;
                            nc = 2 * L - 1;
                            nd = 2;
                        } else if(c >= L) {
                            // 4 -> 6
                            nr = c - L + 3 * L;
                            nc = L - 1;
                            nd = 2;
                        } else {
                            // 6 -> 1
                            nr = 0;
                            nc = c + 2 * L;
                        }
                        
                        //nr = cs[c].first;
                        if(G[nr][nc] == '#') {
                            stop = true;
                        } else {
                            r = nr;
                            c = nc;
                            d = nd;
                        }
                    } else if(d == 3 && (nr < 0 || G[nr][nc] == ' ')) {
                        if(c >= 2 * L) {
                            // 1 -> 6
                            nr = 4 * L - 1;
                            nc = c - 2 * L;
                        } else if(c >= L) {
                            // 2 -> 6
                            nr = c - L + 3 * L;
                            nc = 0;
                            nd = 0;
                        } else {
                            // 5 -> 3
                            nr = c + L;
                            nc = L;
                            nd = 0;
                        }

                        //nr = cs[c].second;
                        if(G[nr][nc] == '#') {
                            stop = true;
                        } else {
                            r = nr;
                            c = nc;
                            d = nd;
                        }
                    } else if(G[nr][nc] == '.') {
                        r = nr;
                        c = nc;
                    } else {
                        stop = true;
                    }
                }

                if(stop) {
                    break;
                }
            }
        } else {
            if(v == 0) {
                d = (d + 1) % 4;
            } else {
                d = (d - 1 + 4) % 4; 
            }
        }
    }

    LL ans = 1000LL * (r + 1) + 4LL * (c + 1) + d;

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
