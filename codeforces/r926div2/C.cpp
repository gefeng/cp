#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int K, X, A;
    std::cin >> K >> X >> A;

    int64_t bet = 1;
    int64_t sum = 0;
    while(X) {
        sum += bet;
        if(sum > A) {
            std::cout << "No" << '\n';
            return;
        }
        bet = (sum + 1 + K - 1 - 1) / (K - 1);
        X -= 1;
    } 

    if((A - sum) * K > A) {
        std::cout << "Yes" << '\n';
    } else {
        std::cout << "No" << '\n';
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
