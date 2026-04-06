#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::pair<int, int> A;
    std::cin >> A.first >> A.second;
    
    std::cout << (A == std::pair<int, int>{1, 7} || A == std::pair<int, int>{3, 3} || 
            A == std::pair<int, int>{5, 5} || A == std::pair<int, int>{7, 7} || A == std::pair<int, int>{9, 9} ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
