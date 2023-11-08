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
    for(int i = 0; i < N; i++) {
        ans[i] = i + 1;
    }

    for(int i = 2; i < N; i++) {
        if((ans[i - 2] | ans[i - 1]) == ans[i]) {
            std::swap(ans[i - 2], ans[i]);
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
