#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B;
    std::cin >> A >> B;

    if(A > B) {
        std::swap(A, B);
    }

    int ans = std::min(B - A, A);
    B -= 2 * ans;
    A -= ans;

    if(A == B) {
        ans += 2 * (A / 3);
        ans += A % 3 == 2 ? 1 : 0; 
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
