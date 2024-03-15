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

    if(N % 2 == 1) {
        std::cout << "No" << '\n';
        return;
    }

    std::string ans = "";
    for(int i = 0, j = 0; i < N; i += 2, j ^= 1) {
        ans.push_back((char)(j + 'A'));
        ans.push_back((char)(j + 'A'));
    }

    std::cout << "Yes" << '\n';
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
