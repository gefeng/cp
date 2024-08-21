#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    std::vector<std::vector<int>> pos(3);
    for(int i = 0; i < N; i++) {
        pos[A[i]].push_back(i);
    }

    auto solve = [&](int x) {
        int l = pos[x].front();
        int r = pos[x].back();
        int y = (x - 1 + 3) % 3;
        int64_t res = 0;
        auto it = std::upper_bound(pos[y].begin(), pos[y].end(), l);
        if(it == pos[y].end() || *it > r) {
            int rr = N;
            int ll = -1;
            if(it != pos[y].end()) {
                rr = *it;
            }

            if(it != pos[y].begin()) {
                it--;
                ll = *it;
            }
            
            res = int64_t(l - ll) * (rr - r);
        }
        return res;
    };

    int64_t ans = int64_t(1 + N) * N / 2;
    
    std::vector<std::pair<int, int>> a;
    for(int i = 0; i < 3; i++) {
        ans -= solve(i);
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
