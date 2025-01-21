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

    int ans = 0;
    if(N % 4 != 0) {
        ans = 365;
    } else if(N % 100 != 0) {
        ans = 366;
    } else if(N % 400 != 0) {
        ans = 365;
    } else {
        ans = 366;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
