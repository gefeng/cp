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
    std::vector<std::vector<int>> pos(N + 1);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        pos[A[i]].push_back(i);
    }

    int ans = 0;
    int l = 0;
    int r = 0;
    while(r < N) {
        int n_r = -1;
        for(int i = l; i <= r; i++) {
            auto it = std::upper_bound(pos[A[i]].begin(), pos[A[i]].end(), i);
            if(it == pos[A[i]].end()) {
                std::cout << ans + 1 << '\n';
                return;
            } 
            n_r = std::max(n_r, *it);
        }

        ans += 1;
        l = r + 1;
        r = n_r;
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
