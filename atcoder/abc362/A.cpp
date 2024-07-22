#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::array<int, 3> A;
    std::string S;
    for(int i = 0; i < 3; i++) {
        std::cin >> A[i];
    }

    std::cin >> S;
   
    int ans = 0;
    if(S == "Red") {
        ans = std::min(A[1], A[2]); 
    } else if(S == "Green") {
        ans = std::min(A[0], A[2]);
    } else {
        ans = std::min(A[0], A[1]);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
