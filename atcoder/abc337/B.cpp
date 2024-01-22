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

    int i = 0;
    int n = S.size();
    while(i < n && S[i] == 'A') {
        i += 1;  
    }

    while(i < n && S[i] == 'B') {
        i += 1;
    }

    while(i < n && S[i] == 'C') {
        i += 1;
    }

    std::cout << (i == n ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
