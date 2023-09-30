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

    bool inc = 1;
    int pre = -1;
    while(N) {
        int d = N % 10;
        if(d <= pre) {
            inc = 0;
            break;
        }
        pre = d;
        N /= 10;
    }

    std::cout << (inc ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
