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
    
    std::string ans = "Unknown";
    if(S == "red") {
        ans = "SSS";
    } else if(S == "blue") {
        ans = "FFF";
    } else if(S == "green") {
        ans = "MMM";
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
