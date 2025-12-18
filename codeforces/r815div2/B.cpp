#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int>(2e9) + 10;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int max1 = 0;
    int max2 = 0;
    int min1 = INF;
    int min2 = INF;

    for(int x : A) {
        if(x > max1) {
            max2 = max1;
            max1 = x;
        } else if(x > max2) {
            max2 = x;
        }

        if(x < min1) {
            min2 = min1;
            min1 = x;
        } else if(x < min2) {
            min2 = x;
        }
    }

    std::cout << max1 - min1 + max2 - min2 << '\n';
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
