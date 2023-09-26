#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case(int T) {
    int R, C, A, B;
    std::cin >> R >> C >> A >> B;

    int win = C < R ? 0 : 1;

    std::cout << "Case #" << T << ": " << (win == 0 ? "YES" : "NO") << '\n';
}

int main() {
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
