#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, S;
    std::cin >> N >> S;
    
    if(S / N == 1) {
        std::cout << "No" << '\n';
        return;
    }

    std::vector<int> ans(N, S / N);
    for(int i = 0; i < S % N; i++) {
        ans[i] += 1;
    }

    std::cout << "Yes" << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
    std::cout << 1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
