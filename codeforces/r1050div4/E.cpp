#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> pos(N + 1);
    for(int i = 0; i < N; i++) {
        pos[A[i]].push_back(i);
    }

    for(int i = 0; i <= N; i++) {
        int size = pos[i].size();
        if(size && size % K != 0) {
            std::cout << 0 << '\n';
            return;
        }
    }

    int64_t ans = 0;
    int l = -1;
    for(int i = 0; i < N; i++) {
        int p = std::lower_bound(pos[A[i]].begin(), pos[A[i]].end(), i) - pos[A[i]].begin();
        int k = pos[A[i]].size() / K;
        if(p >= k) {
            int j = pos[A[i]][p - k];
            l = std::max(l, j);
        }

        ans += i - l;
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
