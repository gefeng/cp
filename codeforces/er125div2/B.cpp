#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, B, X, Y;
    std::cin >> N >> B >> X >> Y;

    int64_t ans = 0;
    int64_t now = 0;
    for(int i = 0; i < N; i++) {
        if(now + X <= B) {
            now += X;
        } else {
            now -= Y;
        }
        ans += now;
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
