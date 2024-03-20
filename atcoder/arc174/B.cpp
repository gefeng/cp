#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::vector<int> A(5);
    std::vector<int> B(5);
    int64_t sum_stars = 0;
    int64_t sum_reviews = 0;
    for(int i = 0; i < 5; i++) {
        std::cin >> A[i];
        sum_stars += (int64_t)A[i] * (i + 1);
        sum_reviews += (int64_t)A[i];
    }

    for(int i = 0; i < 5; i++) {
        std::cin >> B[i];
    }

    int64_t d = 3 * sum_reviews - sum_stars;
    if(d <= 0) {
        std::cout << 0 << '\n';
        return;
    }

    // only add 4-star
    int64_t ans = d * B[3];
    
    // only add 5-star
    ans = std::min(ans, (d + 1) / 2 * B[4]);

    // add one 4-star and x 5-star
    ans = std::min(ans, B[3] + d / 2 * B[4]);

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
