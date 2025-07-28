#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <set>

void run_case() {
    int N, C;
    std::cin >> N >> C;
    
    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = N;
    std::ranges::sort(A);

    std::vector<int64_t> now(A);
    while(!now.empty()) {
        std::vector<int64_t> nxt;
        int n = now.size();
        int64_t max_v = -1;
        int p = -1;
        for(int i = 0; i < n; i++) {
            if(now[i] <= C && max_v < now[i]) {
                max_v = now[i];
                p = i;
            }
        }
        if(p == -1) {
            break;
        }
        ans -= 1;
        for(int i = 0; i < n; i++) {
            if(i != p) {
                nxt.push_back(now[i] * 2);
            }
        }
        now = std::move(nxt);
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
