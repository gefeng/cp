#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::string t = "1543";

    int ans = 0;
    for(int i = 0; i < std::min(N, M) / 2; i++) {
        int min_r = i;
        int min_c = i;
        int max_r = N - 1 - i;
        int max_c = M - 1 - i;
        int r = i;
        int c = i;
        int d = 0;

        std::string s = "";
        do {
            s.push_back(A[r][c]);
            int nr = r + DR[d];
            int nc = c + DC[d];
            if(nr >= min_r && nc >= min_c && nr <= max_r && nc <= max_c) {
                r = nr;
                c = nc;
            } else {
                d += 1;
                r += DR[d];
                c += DC[d];
            }
        } while(r != i || c != i);

        int m = s.size();
        for(int j = 0; j < m; j++) {
            std::string x = "";
            for(int k = 0; k < 4; k++) {
                x.push_back(s[(j + k) % m]);
            }
            if(x == t) {
                ans += 1;
            }
        }
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
