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

    int n = 1 << N;

    std::vector<int> used(n, 0);
    std::vector<int> ans(n, -1);
    for(int i = N, j = 0; i >= 0; i--) {
        int suffix = (1 << i) - 1;
        ans[j++] = suffix;
        used[suffix] = 1;
    
        for(int x = 1; (x << (i + 1)) + suffix < n; x++) {
            int y = (x << (i + 1)) + suffix;
            if(!used[y] && j < n) {
                ans[j++] = y;
                used[y] = 1;
            }
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
