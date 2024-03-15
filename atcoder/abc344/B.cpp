#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::vector<int> A;
    
    while(true) {
        int X;
        std::cin >> X;

        A.push_back(X);
        if(X == 0) {
            break;
        }
    }

    std::reverse(A.begin(), A.end());
    
    for(int x : A) {
        std::cout << x << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
