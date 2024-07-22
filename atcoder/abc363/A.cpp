#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int R;
    std::cin >> R;

    int ans = 0;
    if(R <= 99) {
        ans = 100 - R;
    } else if(R <= 199) {
        ans = 200 - R;
    } else {
        ans = 300 - R;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
