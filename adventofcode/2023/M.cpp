#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

std::vector<std::string> G;
std::vector<int> A;

void run_case1() {
    int m = A.size();
    int64_t ans = 0; 

    for(int i = 0, j = 0; i < m; i++) {
        int size = A[i];
        
        std::vector<std::string> g;
        for(int k = 0; k < size; k++) {
            g.push_back(G[j + k]); 
        } 

        int n = g[0].size();
        bool found = false;
        for(int r = 0; r < size - 1; r++) {
            if(g[r] != g[r + 1]) {
                continue; 
            }

            bool reflected = true;
            for(int p1 = r, p2 = r + 1; p1 >= 0 && p2 < size; p1--, p2++) {
                if(g[p1] != g[p2]) {
                    reflected = false;
                    break;
                }
            }

            if(reflected) {
                found = true;
                ans += (r + 1) * 100;
                break;
            }
        }

        if(!found) {
            for(int c = 0; c < n - 1; c++) {
                bool reflected = true;
                for(int p1 = c, p2 = c + 1; p1 >= 0 && p2 < n; p1--, p2++) {
                    bool same = true;
                    for(int r = 0; r < size; r++) {
                        if(g[r][p1] != g[r][p2]) {
                            same = false;
                            break;
                        }
                    }

                    if(!same) {
                        reflected = false;
                        break;
                    }
                }

                if(reflected) {
                    ans += c + 1;
                    break;
                }
            }
        }

        j += size;
    }

    std::cout << ans << '\n';
}

void run_case2() {
    int m = A.size();
    int64_t ans = 0; 

    for(int i = 0, j = 0; i < m; i++) {
        int size = A[i];
        
        std::vector<std::string> g;
        for(int k = 0; k < size; k++) {
            g.push_back(G[j + k]); 
        } 

        int n = g[0].size();
        bool found = false;
        for(int r = 0; r < size - 1; r++) {
            int cnt = 0;
            for(int p1 = r, p2 = r + 1; p1 >= 0 && p2 < size; p1--, p2++) {
                for(int c = 0; c < n; c++) {
                    if(g[p1][c] != g[p2][c]) {
                        cnt += 1;
                    }
                }
            }

            if(cnt == 1) {
                found = true;
                ans += (r + 1) * 100;
                break;
            }
        }

        if(!found) {
            for(int c = 0; c < n - 1; c++) {
                int cnt = 0;
                for(int p1 = c, p2 = c + 1; p1 >= 0 && p2 < n; p1--, p2++) {
                    for(int r = 0; r < size; r++) {
                        if(g[r][p1] != g[r][p2]) {
                            cnt += 1;
                        }
                    }
                }

                if(cnt == 1) {
                    ans += c + 1;
                    break;
                }
            }
        }

        j += size;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string S;
    int size = 0;
    while(std::getline(std::cin, S)) {
        if(!S.empty()) {
            G.push_back(S);
            size += 1;
        } else {
            A.push_back(size);
            size = 0;
        }
    }

    A.push_back(size);

    run_case1();
    run_case2();
}
