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

    int x = 1 << N;
    int y = 0;
    for(int i = 1; i < N / 2; i += 1) {
        x += 1 << i;
    }

    for(int i = N / 2; i < N; i++) {
        y += 1 << i;
    }
 
    int ans = x - y;

    std::cout << ans << '\n';
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
