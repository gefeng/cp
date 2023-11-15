#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> pos(N + 1);
    for(int i = 0; i < N; i++) {
        pos[A[i]].push_back(i);
    }

    int min_t = INF;
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        if(pos[i].empty()) {
            continue;
        }

        int pre = -1;
        int t = 0;
        for(int p : pos[i]) {
            if(pre == -1) {
                t = std::max(t, p);
            } else {
                t = std::max(t, (p - pre) / 2);
            }
            pre = p;
        }

        t = std::max(t, N - 1 - pos[i].back());

        if(t < min_t) {
            min_t = t;
            ans = i;
        }
    }

    std::cout << ans << ' ' << min_t << '\n';
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
