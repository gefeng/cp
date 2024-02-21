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

    std::string ans = "";
    for(int i = 0; i < N + N + 1; i++) {
        if(i % 2 == 0) {
            ans.push_back('1');
        } else {
            ans.push_back('0');
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
