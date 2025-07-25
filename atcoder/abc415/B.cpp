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
    for(int i = 0; i < n; i++) {
        if(S[i] == '#') {
            std::cout << i + 1 << ',';
            i += 1;
            while(i < n && S[i] == '.') {
                i += 1;
            }
            std::cout << i + 1 << '\n';
        } 
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
