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
    
    int p1 = -1;
    int p2 = -1;
    for(int i = 0; i < 3; i++) {
        if(S[i] == 'R') {
            p1 = i;
        } else if(S[i] == 'M') {
            p2 = i;
        }
    }

    std::cout << (p1 < p2 ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
