#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int R = 1000000000;

std::vector<std::string> G;

void run_case1() {
    int n = G.size();
    int m = G[0].size();
    
    int64_t ans = 0;
    for(int c = 0; c < m; c++) {
        int pos = 0;
        for(int r = 0; r < n; r++) {
            if(G[r][c] == '#') {
                pos = r + 1;
            } else if(G[r][c] == 'O') {
                ans += n - pos;
                pos += 1;
            }
        }
    }

    std::cout << ans << '\n';
}

void run_case2() {
    int n = G.size();
    int m = G[0].size();

    auto tilt_north = [&]() {
        for(int c = 0; c < m; c++) {
            int pos = 0;
            for(int r = 0; r < n; r++) {
                if(G[r][c] == '#') {
                    pos = r + 1;
                } else if(G[r][c] == 'O') {
                    G[pos][c] = 'O';
                    if(pos != r) {
                        G[r][c] = '.';
                    }
                    pos += 1; 
                }
            }
        }
    };
    auto tilt_west = [&]() {
        for(int r = 0; r < n; r++) {
            int pos = 0;
            for(int c = 0; c < m; c++) {
                if(G[r][c] == '#') {
                    pos = c + 1;
                } else if(G[r][c] == 'O') {
                    G[r][pos] = 'O';
                    if(pos != c) {
                        G[r][c] = '.';
                    }
                    pos += 1;
                }
            }
        }
    };
    auto tilt_south = [&]() {
        for(int c = 0; c < m; c++) {
            int pos = n - 1;
            for(int r = n - 1; r >= 0; r--) {
                if(G[r][c] == '#') {
                    pos = r - 1;
                } else if(G[r][c] == 'O') {
                    G[pos][c] = 'O';
                    if(pos != r) {
                        G[r][c] = '.';
                    }
                    pos -= 1;
                }
            }
        }
    };
    auto tilt_east = [&]() {
        for(int r = 0; r < n; r++) {
            int pos = m - 1;
            for(int c = m - 1; c >= 0; c--) {
                if(G[r][c] == '#') {
                    pos = c - 1;
                } else if(G[r][c] == 'O') {
                    G[r][pos] = 'O';
                    if(pos != c) {
                        G[r][c] = '.';
                    }
                    pos -= 1;
                }
            }
        }
    };

    auto get_load = [&](std::vector<std::string>& g) {
        int64_t load = 0;
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                if(g[r][c] == 'O') {
                    load += n - r;
                }
            }
        }
        return load;
    };
    
    std::vector<std::vector<std::string>> save;
    std::vector<int64_t> save_load;
    int repeat = 1000;
    for(int i = 0; i < repeat; i++) {
        tilt_north();
        tilt_west();
        tilt_south();
        tilt_east();

        save_load.push_back(get_load(G)); 
    }

    int cycle = 0;
    int begin = -1;
    std::map<int, int> pos;
    for(int i = 0; i < repeat; i++) {
        if(pos.find(save_load[i]) != pos.end()) {
            cycle = i - pos[save_load[i]]; 
        }
        pos[save_load[i]] = i;
    }

    for(int i = 0; i < repeat; i++) {
        if(save_load[i] == save_load[i + cycle]) {
            begin = i;
            break;
        }
    }

    std::cout << "cycle = " << cycle << " start at index = " << begin << '\n';
    
    std::cout << save_load[((R - begin - 1) % cycle) + begin] << '\n'; 
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    std::string S;
    while(std::getline(std::cin, S)) {
        G.push_back(S);
    }

    //run_case1();
    run_case2();
}
