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

    int ans = 0;
    int max_v = 0;
    for(int x = 2; x <= N; x++) {
        int sum = 0;
        for(int c = 1; c * x <= N; c++) {
            sum += c * x;
        }
        if(sum > max_v) {
            max_v = sum;
            ans = x;
        }
    }

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
