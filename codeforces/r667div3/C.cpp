#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int>(2e9);

void run_case() {
    int N, X, Y;
    std::cin >> N >> X >> Y;
    
    int max_v = INF;
    std::vector<int> ans(N, 0);
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int d = j - i;
            if((Y - X) % d != 0) {
                continue;
            }

            d = (Y - X) / d;
            std::vector<int> a(N);
            a[i] = X;
            a[j] = Y;
            for(int k = j - 1; k >= 0; k--) {
                a[k] = a[k + 1] - d;
            }
            
            for(int k = i + 1; k < j; k++) {
                a[k] = a[k - 1] + d;
            }
            
            for(int k = j + 1; k < N; k++) {
                a[k] = a[k - 1] + d;
            }

            if(a[0] >= 1 && a.back() < max_v) {
                max_v = a.back();
                ans = std::move(a);
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
