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
    if(A == B) {
        ans = 1;
    } else {
        if(std::abs(A - B) % 2 == 1) {
            ans = 2;
        } else {
            ans = 3;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}