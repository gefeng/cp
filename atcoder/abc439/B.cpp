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
    int N;
    std::cin >> N;

    std::set<int> s; 
    int x = N;
    while(s.find(x) == s.end()) {
        s.insert(x);
        int y = 0;
        while(x) {
            y += (x % 10) * (x % 10);
            x /= 10;
        }
        x = y;
    }

    std::cout << (x == 1 ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
