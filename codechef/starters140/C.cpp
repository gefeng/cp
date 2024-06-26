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
        for(int i = 0; i < N; i += 2) {
            ans[i] = i + 1;
            ans[i + 1] = N - i;
        }
    } else {
        for(int i = 0; i < N - 1; i += 2) {
            ans[i] = i + 1;
            ans[i + 1] = N - 1 - i;
        }
        ans[N - 1] = N;
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
