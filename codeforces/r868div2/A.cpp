#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    bool found = false;
    std::vector<int> ans(N, 1);
    for(int i = 0; i <= N; i++) {
        int j = N - i;
        if(i * (i - 1) / 2 + j * (j - 1) / 2 == K) {
            found = true;
            for(int k = 0; k < j; k++) {
                ans[k] = -1;
            }
            break;
        }
    }

    if(!found) {
        std::cout << "NO" << '\n';
    } else {
        std::cout << "YES" << '\n';
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
