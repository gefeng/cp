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

    int l = -1;
    int r = -1;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int A;
        char C;
        std::cin >> A >> C;
        
        if(C == 'L') {
            if(l != -1) {
                ans += std::abs(A - l);
            }
            l = A;
        } else {
            if(r != -1) {
                ans += std::abs(A - r);
            }
            r = A;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
