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

    int sum = 0;
    int last = -1;
    for(int i = 0; i < N; i++) {
        sum += A[i]; 
        if(sum % 3 == 0) {
            last = i;
        }
    }

    if(last == -1) {
        std::cout << "Yes" << '\n';
        return;
    }

    for(int i = last + 1; i < N; i++) {
        std::vector<int> a(A);
        std::reverse(a.begin(), a.begin() + i + 1);
        sum = 0;
        bool good = true;
        for(int j = 0; j < N; j++) {
            sum += a[j];
            if(sum % 3 == 0) {
                good = false;
            }
        }
        if(good) {
            std::cout << "Yes" << '\n';
            return;
        }
    }

    std::cout << "No" << '\n';
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
