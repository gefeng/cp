#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <deque>

void run_case() {
    int N;
    std::cin >> N;

    if(N == 1) {
        std::cout << 1 << '\n';
        return;
    }

    if(N & 1) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<int> ans(N, 0);
    for(int i = 0; i < N; i++) {
        ans[i] = i + 1;
    }

    for(int i = 0, j = N - 1; i < j; i += 2, j -= 2) {
        if(i + 1 == j) {
            std::swap(ans[i], ans[j]);
        } else {
            std::swap(ans[i], ans[i + 1]);
            std::swap(ans[j], ans[j - 1]);
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
