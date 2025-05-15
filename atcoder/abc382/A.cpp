#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, D;
    std::cin >> N >> D;
    
    std::string S;
    std::cin >> S;
    
    int cookie = 0;
    for(char c : S) {
        if(c == '@') {
            cookie += 1;
        }
    }

    std::cout << N - std::max(0, cookie - D) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
