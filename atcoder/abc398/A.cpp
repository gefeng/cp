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
    
    std::string ans(N, '-');
    
    if(N % 2 == 0) {
        ans[N / 2 - 1] = '=';
        ans[N / 2] = '=';
    } else {
        ans[N / 2] = '=';
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
