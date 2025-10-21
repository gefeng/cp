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

    int ans = 0;
    if(A >= B) {
        ans = A;
    } else {
        int x = B - A;
        if(x > A) {
            ans = 0;
        } else {
            ans = A - x;
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
