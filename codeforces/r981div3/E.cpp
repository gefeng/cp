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

    std::vector<int> vis(N, 0);
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(vis[i]) {
            continue;
        }
        
        int v = i;
        int cnt = 0;
        while(!vis[v]) {
            vis[v] = 1;
            cnt += 1;
            v = A[v];
        }

        if(cnt % 2 == 0) {
            ans += std::max(0, cnt - 2) / 2;
        } else {
            ans += std::max(0, cnt - 1) / 2;
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
