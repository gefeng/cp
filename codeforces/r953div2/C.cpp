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
    int64_t K;
    std::cin >> N >> K;
    
    if(K % 2 == 1) {
        std::cout << "No" << '\n';
        return;
    }

    std::vector<int> ans(N, 0);
    
    int i = 0;
    while(K) {
        int x = i + 1;
        int y = N - i;
        if(x > y) {
            break;
        }

        if((int64_t)(y - x) * 2 <= K) {
            K -= (y - x) * 2;
            ans[i] = y;
            ans[N - i - 1] = x;
        } else {
            y = x + K / 2;
            ans[i] = y;
            ans[y - 1] = x;
            K = 0;
            break;
        }
        i += 1;
    }

    if(K) {
        std::cout << "No" << '\n';
        return;
    }

    for(int i = 0; i < N; i++) {
        if(ans[i] == 0) {
            ans[i] = i + 1;
        }
    }

    std::cout << "Yes" << '\n';
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
