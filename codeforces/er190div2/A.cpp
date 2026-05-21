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

    int64_t ans = static_cast<int64_t>(A) * N;

    
    int64_t t = N / 3;
    int64_t r = N % 3;
    int64_t c = t * B + std::min(r * A, static_cast<int64_t>(B));    

    ans = std::min(ans, c);

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
