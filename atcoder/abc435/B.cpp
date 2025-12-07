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

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int sum = 0;
        for(int j = i; j < N; j++) {
            sum += A[j]; 
            bool good = true;
            for(int k = i; k <= j; k++) {
                if(sum % A[k] == 0) {
                    good = false;
                }
            }
            if(good) {
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
