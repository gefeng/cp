#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

int dfs(std::vector<std::vector<int>>& G, int cur, int used, std::vector<int>& order) {
    if(cur == 9) {
        bool ok = true;
        std::vector<int> row(3, 0);
        std::vector<int> col(3, 0);
        int d1 = 0;
        int d2 = 0;
        for(int x : order) {
            int r = x / 3;
            int c = x % 3;
            int v = G[r][c];
            if(row[r] == 0) {
                row[r] = v;
            } else if(row[r] < 10) {
                if(v == row[r]) {
                    ok = false;
                    break;
                }
                row[r] = 10;
            }

            if(col[c] == 0) {
                col[c] = v;
            } else if(col[c] < 10) {
                if(v == col[c]) {
                    ok = false;
                    break;
                }
                col[c] = 10;
            }

            if(r == c) {
                if(d1 == 0) {
                    d1 = v;
                } else if(d1 < 10) {
                    if(d1 == v) {
                        ok = false;
                        break;
                    }
                    d1 = 10;
                } 
            }

            if(r + c == 2) {
                if(d2 == 0) {
                    d2 = v;
                } else if(d2 < 10) {
                    if(d2 == v) {
                        ok = false;
                        break;
                    }
                    d2 = 10;
                } 
            }
        } 

        return ok ? 1 : 0;
    }

    int res = 0;
    for(int i = 0; i < 9; i++) {
        if(used & (1 << i)) {
            continue;
        }
        order.push_back(i);
        res += dfs(G, cur + 1, used ^ (1 << i), order);
        order.pop_back();
    }

    return res;
}

void run_case() {
    std::vector<std::vector<int>> G(3, std::vector<int>(3, 0));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cin >> G[i][j];
        }
    }

    std::vector<int> order;
    int cnt = dfs(G, 0, 0, order);
    int tot = 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2;
    
    std::cout << std::setprecision(20) << (double)cnt / tot << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
