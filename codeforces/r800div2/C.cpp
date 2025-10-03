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
    
    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int last = N - 1;
    while(last >= 0 && A[last] == 0) {
        last -= 1;
    }

    std::vector<int64_t> a(N, 0);
    for(int i = 0; i < last; i++) {
        a[i] = 1;
    }

    for(int i = last; i >= 0; i--) {
        if(A[i] > a[i]) {
            std::cout << "No" << '\n';
            return;
        } 
        if(A[i] == a[i]) {
            continue;
        }
        if(i == 0) {
            std::cout << "No" << '\n';
            return;
        }

        int64_t d = a[i] - A[i];
        a[i - 1] += d - 1;
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
