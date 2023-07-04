#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    int ub = 1000;
    while(true) {
        if(N < ub) {
            int x = ub / 1000;
            std::cout << (N / x) * x << '\n';
            return;
        }

        ub *= 10;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
