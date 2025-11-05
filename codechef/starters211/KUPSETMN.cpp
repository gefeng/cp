#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, W;
    std::cin >> N >> W;

    int n = (1 << (N + 1)) - 1;
    int m = 1 << N;
    std::vector<int> ans(n);
    
    for(int i = W, j = n - m; i <= m; i++, j++) {
        ans[j] = i;
    }

    for(int i = W - 1, j = n - 1; i >= 1; i--, j--) {
        ans[j] = i;
    }

    for(int i = n - m - 1; i >= 0; i--) {
        int x = ans[i * 2 + 1];
        int y = ans[i * 2 + 2];
        if(x == W || y == W) {
            ans[i] = W;
        } else {
            ans[i] = std::min(x, y);
        }
    }

    for(int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
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
