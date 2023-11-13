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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto get_digits = [](int x) {
        int d = -1;
        while(x) {
            if(d != -1 && x % 10 != d) {
                return -1;
            }
            d = x % 10;
            x /= 10;
        }
        return d;
    };

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int m = i + 1;
        for(int j = 1; j <= A[i]; j++) {
            int d = j;
           
            int x = get_digits(m);
            int y = get_digits(d);
            if(x == y && x != -1) {
                ans += 1; 
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
