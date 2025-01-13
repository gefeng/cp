#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, A, B;
    std::cin >> N >> A >> B;
    A -= 1;
    B -= 1;
    
    if(A < B) {
        std::cout << ((B - A) % 2 == 0 ? "Yes" : "No") << '\n';
    } else {
        std::cout << ((A - B) % 2 == 0 ? "Yes" : "No") << '\n';
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
