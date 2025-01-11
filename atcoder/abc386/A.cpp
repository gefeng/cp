#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    std::set<int> s;
    for(int i = 0; i < 4; i++) {
        int X;
        std::cin >> X;
        s.insert(X);
    }

    std::cout << (s.size() == 2 ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
