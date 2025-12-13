#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    std::vector<int> pos(N, 0);
    for(int i = 0; i < N; i++) {
        pos[A[i]] = i;
    }

    int64_t ans = 0;
    std::vector<int> vis(N, 0);
    for(int i = 0; i < N; i++) {
        if(vis[i]) {
            continue;
        }
        
        int now = i;
        int len = 0;
        while(!vis[now]) {
            vis[now] = 1;
            now = A[now];
            len += 1;
        }
        ans += static_cast<int64_t>(len - 1) * len / 2;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
