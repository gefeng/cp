#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, A, B;
    std::cin >> N >> A >> B;

    int ans = 0;
    if(2 * A > B) {
        ans = B * (N / 2) + A * (N % 2);
    } else {
        ans = N * A;
    }

    std::cout << ans << '\n';
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
