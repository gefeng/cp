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

    int x = 1;
    while(x * 2 <= N) {
        x *= 2;
    }
    if(x == N) {
        std::cout << -1 << '\n';
        return;
    }
    
    std::vector<int> ans(N);
    
    ans.back() = 1;
    
    std::vector<int> vis(N + 1, 0);
    vis[1] = 1;
    for(int i = N - 2; i > 0; i--) {
        ans[i] = (i + 1) ^ 1;
        vis[ans[i]] = 1;
    }

    for(int i = 1; i <= N; i++) {
        if(!vis[i]) {
            ans[0] = i;
            break;
        }
    }

    if(N % 2 == 0) {
        for(int i = 1; i < N - 1; i += 2) {
            if((N ^ (i + 1)) < N) {
                std::swap(ans[0], ans[i]);
                break;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
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
