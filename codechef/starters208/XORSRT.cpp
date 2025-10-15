#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    if(K == 0) {
        for(int i = 1; i <= N; i++) {
            std::cout << i << " \n"[i == N];
        }
        return;
    }

    std::vector<int> ans(N);
    std::iota(ans.begin(), ans.end(), 1);
    for(int i = 1; i <= N; i++) {
        int x = i ^ K;
        if(x == 0 || x > i) {
            continue;
        }

        // [x...i]
        if(x + 1 == i) {
            std::swap(ans[x - 1], ans[x]);
        } else {
            int y = 0;
            for(int b = 29; b >= 0; b--) {
                if(K & (1 << b)) {
                    y |= 1 << b;
                    break;
                }
                if(x & (1 << b)) {
                    y |= 1 << b;
                }
            }
            int k = x + 1;
            for(int j = x; j < y - 1; j++, k++) {
                ans[j - 1] = k;
            }

            ans[y - 2] = i;
            ans[y - 1] = x;
            
            for(int j = y + 1; j <= i; j++, k++) {
                ans[j - 1] = k;
            }
        }

        for(int i = 0; i < N; i++) {
            std::cout << ans[i] << " \n"[i == N - 1];
        }
        return;
    }

    std::cout << -1 << '\n';
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
