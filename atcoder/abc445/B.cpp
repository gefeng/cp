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

    std::vector<std::string> A(N);
    int m = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        m = std::max(m, static_cast<int>(A[i].size()));
    }

    for(auto& s : A) {
        int k = (m - s.size()) / 2;
        std::string t(k, '.');
        t += s;
        t += std::string(k, '.');
        std::cout << t << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
