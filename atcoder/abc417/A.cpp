#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, A, B;
    std::cin >> N >> A >> B;

    std::string S;
    std::cin >> S;

    std::cout << S.substr(A, N - A - B) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
