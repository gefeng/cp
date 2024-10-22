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
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum += A[i];
    }

    int t = sum / N;
    int r = sum % N;
    int64_t bal = 0;
    for(int i = 0; i < N; i++) {
        int x = N - i <= r ? t + 1 : t;

        if(x >= A[i]) {
            bal += x - A[i];
        } else {
            bal -= A[i] - x;
        }
        if(bal < 0) {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::cout << "Yes" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
