#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S;
    std::cin >> S;

    int n = S.size();
    int sum = 0;
    for(char c : S) {
        sum += c - 'a' + 1; 
    }
    
    if(n % 2 == 0) {
        std::cout << "Alice " << sum << '\n';
    } else {
        int x = sum - (S[0] - 'a' + 1);
        int y = sum - (S.back() - 'a' + 1);
        
        if(x > y) {
            std::cout << (x > (sum - x) ? "Alice " : "Bob ") << std::abs(x - sum + x) << '\n';
        } else {
            std::cout << (y > (sum - y) ? "Alice " : "Bob ") << std::abs(y - sum + y) << '\n';
        }
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
