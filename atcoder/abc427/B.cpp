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

    auto f = [](int x) {
        int res = 0;
        while(x) {
            res += x % 10;
            x /= 10;
        }
        return res;
    };

    int sum = 1;
    for(int i = 1; i < N; i++) {
        int now = f(sum);
        sum += now;
    }

    std::cout << sum << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
