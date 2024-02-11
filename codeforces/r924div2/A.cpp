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

    if(A % 2 == 0) {
        int x = A / 2;
        int y = B * 2;

        if(x > y) {
            std::swap(x, y);
        }

        if(x != A || y != B) {
            std::cout << "Yes" << '\n';
            return;
        }
    }

    if(B % 2 == 0) {
        int x = B / 2;
        int y = A * 2;
        
        if(x > y) {
            std::swap(x, y);
        }

        if(x != A || y != B) {
            std::cout << "Yes" << '\n';
            return;
        }
    }

    std::cout << "No" << '\n';
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
