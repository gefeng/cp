#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::cout << ((n * m) - 1 == k ? "yes" : "no") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while(t--) {
        run_case();
    }
}
