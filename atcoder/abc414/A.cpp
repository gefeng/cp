#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, L, R;
    std::cin >> N >> L >> R;

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int X, Y;
        std::cin >> X >> Y;

        if(X <= L && Y >= R) {
            ans += 1;
        }
    }
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
