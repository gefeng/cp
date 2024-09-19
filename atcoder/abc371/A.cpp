#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::vector<std::string> A(3);
    for(int i = 0; i < 3; i++) {
        std::cin >> A[i];
    }

    std::string ans = "A";
    
    if((A[0] == "<" && A[2] == "<") || (A[0] == ">" && A[2] == ">")) {
        ans = "B";
    } else if((A[1] == "<" && A[2] == ">") || (A[1] == ">" && A[2] == "<")) {
        ans = "C";
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
