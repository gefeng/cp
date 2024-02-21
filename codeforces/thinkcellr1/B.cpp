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

    if(N == 3) {
        std::cout << 1 << ' ' << 2 << ' ' << 3 << '\n';
    } else {
        std::vector<int> ans(N);
        if(N % 2 == 0) {
            for(int i = 0, x = N; i < N; i += 2, x -= 2) {
                ans[i] = x;
            }

            for(int i = 1; i < N; i += 2) {
                ans[i] = i;
            }
        } else {
            for(int i = 0, x = N; i < N; i += 2, x -= 2) {
                ans[i] = x;
            }

            for(int i = 1; i < N; i += 2) {
                ans[i] = i + 1;
            }
        }

        for(int i = 0; i < N; i++) {
            std::cout << ans[i] << " \n"[i == N - 1];
        }
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
