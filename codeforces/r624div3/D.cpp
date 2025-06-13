#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B, C;
    std::cin >> A >> B >> C;
    
    int min_v = A + B + C - 3;
    std::array<int, 3> ans = {1, 1, 1};
    
    for(int a = 1; a <= (A << 1); a++) {
        for(int b = a; b <= B * 2; b += a) {
            for(int i = -1; i <= 1; i++) {
                int c = (C / b + i) * b;
                if(c >= b) {
                    int cnt = std::abs(A - a) + std::abs(B - b) + std::abs(c - C);
                    if(cnt < min_v) {
                        min_v = cnt;
                        ans[0] = a;
                        ans[1] = b;
                        ans[2] = c;
                    }
                }
            }
        }
    }

    std::cout << min_v << '\n';
    for(int i = 0; i < 3; i++) {
        std::cout << ans[i] << " \n"[i == 2];
    }
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
