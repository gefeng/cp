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
    int64_t X;
    std::cin >> N >> X;

    std::vector<int64_t> a(N);
    int64_t d = 0;
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        int64_t A, B, C;
        std::cin >> A >> B >> C;
        
        a[i] = A * B - C;
        d += A * (B - 1);
    }

    std::ranges::sort(a);

    if(d >= X) {
        std::cout << ans << '\n';
        return;
    } 

    X -= d;
    ans = a.back() > 0 ? (X + a.back() - 1) / a.back() : -1;

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
