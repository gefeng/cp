#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int pre = A.back();
    for(int i = N - 2; i >= 0; i--) {
        if(A[i] > pre) {
            int x = A[i];
            while(x) {
                if(x % 10 > pre) {
                    std::cout << "No" << '\n';
                    return;
                }
                pre = x % 10;
                x /= 10;
            }
        } else {
            pre = A[i];
        }
    }

    std::cout << "Yes" << '\n';
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
