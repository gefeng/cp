#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    int n = int(sqrt(N));
    int m = int(sqrt(M));

    int64_t ans = 0;
    for(int c1 = 1; c1 <= n; c1++) {
        for(int c2 = 1 ; c2 <= m; c2++) {
            if(gcd(c1, c2) == 1) {
                for(int g = c1 + c2; g <= N + M; g += c1 + c2) {
                    if(int64_t(c1) * g <= N && int64_t(c2) * g <= M) {
                        ans += 1;
                    } else {
                        break;
                    }
                }
            }
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
