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

    int p = N;
    for(int i = 1; i < N; i++) {
        if(i % 2 == 1) {
            p -= N - i;
        } else {
            p += N - i;
        }
    }

    std::cout << p << '\n';
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
