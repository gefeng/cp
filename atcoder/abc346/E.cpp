#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int H, W, M;
    std::cin >> H >> W >> M;

    std::vector<std::array<int, 3>> A(M);
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < 3; j++) {
            std::cin >> A[i][j];
        }
    }

    std::vector<int> row(H + 1, 0);
    std::vector<int> col(W + 1, 0);
    
    std::map<int, int64_t> m;
    int cnt_r = 0;
    int cnt_c = 0;
    for(int i = M - 1; i >= 0; i--) {
        int color = A[i][2];
        if(A[i][0] == 1) {
            int r = A[i][1];
            if(row[r] || cnt_c == W) {
                continue;
            }

            m[color] += W - cnt_c;
            cnt_r += 1;
            row[r] = 1;
        } else {
            int c = A[i][1];
            
            if(col[c] || cnt_r == H) {
                continue; 
            }

            m[color] += H - cnt_r;
            cnt_c += 1;
            col[c] = 1;
        }
    }

    for(int i = 1; i <= H; i++) {
        if(!row[i] && W != cnt_c) {
            m[0] += W - cnt_c; 
        }
    }
    
    std::cout << m.size() << '\n';
    for(auto [c, f] : m) {
        std::cout << c << ' ' << f << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
