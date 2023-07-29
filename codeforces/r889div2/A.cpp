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

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        int X;
        std::cin >> X;
        X -= 1;

        if(X == i) {
            cnt += 1;
        }
    }

    std::cout << (cnt + 1) / 2 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
