#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    int64_t ans = 0;
    int r = 0;
    int c = 0;
    for(int i = 0; i < N; i++) {
        ans += M * 4;
        int nr = r + A[i].first;
        int nc = c + A[i].second;
        if(i) {
            int dx = r + M - nr; 
            int dy = c + M - nc;
            ans -= (dx + dy) * 2;
        }
        r = nr;
        c = nc;
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
