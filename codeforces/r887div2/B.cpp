#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    int ans = 0;
    for(int i = N; i >= 0; i--) {
        int f1 = i;
        int f2 = N;
    
        int len = 2;
        while(true) {
            int f = f2 - f1;
            if(f < 0 || f > f1) {
                break;
            }

            len += 1;
            f2 = f1;
            f1 = f;
        }

        if(len >= K) {
            ans += 1;
        }
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
