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

    std::vector<int> ans(N);
    if(N % 2 == 0) {
        for(int i = 0, j = N / 2; i < N; i += 2, j--) {
            ans[i] = j;
        }

        for(int i = 1, j = N; i < N; i += 2, j--) {
            ans[i] = j;
        }
    } else {
        for(int i = 0, j = N; i < N; i += 2, j--) {
            ans[i] = j;
        }

        for(int i = 1, j = N / 2; i < N; i += 2, j--) {
            ans[i] = j;
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
