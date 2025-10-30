#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 5000;
constexpr int INF = static_cast<int>(2e9);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> a(20, 1);
    for(int i = 0, j = 1; i < 20; i += 2, j *= 3) {
        a[i] = j;
        a[i + 1] = j * 2;
    }

    for(int i = 0; i < 20; i++) {
        std::cout << a[i] << " \n"[i == 19];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
