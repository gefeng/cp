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

    std::vector<int> eve;
    std::vector<int> odd;
    for(int i = 0; i < N; i++) {
        if(A[i] % 2 == 0) {
            eve.push_back(i);
        } else {
            odd.push_back(i);
        }
    }

    std::sort(odd.begin(), odd.end(), [&](int i, int j) {
                return A[i] < A[j];
            });

    if(eve.size() > 1) {
        std::cout << eve[0] + 1 << ' ' << eve[1] + 1 << '\n';
        return;
    }

    if(odd.size() > 1) {
        int i = odd.back();
        int j = odd[odd.size() - 2];
        if(A[i] + A[j] != 2) {
            std::cout << i + 1 << ' ' << j + 1 << '\n';
            return;
        }
    }

    if(eve.empty()) {
        std::cout << -1 << '\n';
        return;
    }
    
    auto is_prime = [](int x) {
        if(x == 1) {
            return false;
        }
        for(int f = 2; f * f <= x; f++) {
            if(x % f == 0) {
                return false;
            }
        }
        return true;
    };

    if(is_prime(A[eve[0]] + A[odd[0]])) {
        std::cout << -1 << '\n';
        return;
    }

    std::cout << eve[0] + 1 << ' ' << odd[0] + 1 << '\n';
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
