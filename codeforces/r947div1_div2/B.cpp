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

    std::sort(A.begin(), A.end());
    
    if(A[0] == A.back()) {
        std::cout << "Yes" << '\n';
        return;
    }

    std::vector<int> a;
    for(int i = 0; i < N; i++) {
        if(A[i] % A[0] != 0) {
            a.push_back(A[i]);
        }
    }

    if(a.empty()) {
        std::cout << "Yes" << '\n';
        return;
    }

    for(int x : a) {
        if(x % a[0] != 0) {
            std::cout << "No" << '\n';
            return;
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
